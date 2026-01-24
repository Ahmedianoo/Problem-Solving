#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
using namespace std;


struct Emp_Node{
    int data;
    Emp_Node* left;
    Emp_Node* right;


    Emp_Node(int value) {
        data = value;
        left = right = nullptr;
    }




};


struct Node_Dep {
    int data;
    Node_Dep* left;
    Node_Dep* right;
    Emp_Node* subTree;

    Node_Dep(int value) {
        data = value;
        left = right = nullptr;
        subTree = nullptr;
    }




};


Node_Dep* insert_dep_Node(Node_Dep* root, int value) {
    if (!root) {
        return new Node_Dep(value);
    }
    if (value < root->data) {
        root->left = insert_dep_Node(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert_dep_Node(root->right, value);
    }
    return root;

}

Emp_Node* insert_emp_Node(Emp_Node* root, int value) {
    if (!root) {
        return new Emp_Node(value);
    }
    if (value < root->data) {
        root->left = insert_emp_Node(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert_emp_Node(root->right, value);
    }
    return root;

}



Node_Dep* find_node(Node_Dep* root, int DepID) {
    if (!root) return nullptr;

    if (root->data == DepID) return root;

    if (DepID < root->data) return find_node(root->left, DepID);
    
    return find_node(root->right, DepID);
}

Node_Dep* find_node_count(Node_Dep* root, int DepID, int& count) {
    if (!root) {
        return nullptr;
    }
    count++;

    if (root->data == DepID) return root;

    if (DepID < root->data) return find_node_count(root->left, DepID, count);

    return find_node_count(root->right, DepID, count);
}

Emp_Node* find_id(Emp_Node* root, int empID, int& count) {
    if (!root) {
        return nullptr;
    }
    count++;

    if (root->data == empID) return root;

    if (empID < root->data) return find_id(root->left, empID, count);

    return find_id(root->right, empID, count);
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    

    int N, Q;
    cin >> N >> Q;


    /*vector<pair<int, int>> values(N);*/
    vector<pair<int, vector<int>>> values;

    int depID, ID;
    for (int i = 0; i < N; i++) {
        cin >> depID >> ID;

        bool found_depID = false;

        for (int j = 0; j < values.size(); j++) {
            if (values[j].first == depID) {
                found_depID = true;
                values[j].second.push_back(ID);
                break;
            }

        }
        if (!found_depID) {
            values.push_back({ depID ,{ID} });
        }
        
    }

    vector<pair<int, int>> queries(Q);
    for (int i = 0; i < Q; i++) {
        cin >> queries[i].first >> queries[i].second;
        
    }

    Node_Dep* departments = nullptr;

    

    for (auto it = values.begin(); it != values.end(); it++) {

        departments = insert_dep_Node(departments, it->first);
        vector<int> ids = it->second;

        Node_Dep* dep_node = find_node(departments, it->first);
        
        for (int i = 0; i < ids.size(); i++) {
            dep_node->subTree = insert_emp_Node(dep_node->subTree, ids[i]);
        }
    }



    int count;
    bool found;

    for (int i = 0; i < Q; i++) {
        count = 0;
        found = false;
        Node_Dep* dep_node = find_node_count(departments, queries[i].first, count);
        if (!dep_node) {
            cout << count << " " << found << endl;
            continue;
        }
        else
        {
            Emp_Node* emp_dap = find_id(dep_node->subTree, queries[i].second, count);
            if (emp_dap) found = true;
        }
        cout << count << " " << found << endl;


    }




    return 0;
}



//Node_Dep* departments = nullptr;
//
//for (int i = 0; i < N; i++) {
//    int depID, empID;
//    cin >> depID >> empID;
//
//    Node_Dep* dep_node = find_node(departments, depID);
//    if (!dep_node) {
//        departments = insert_dep_Node(departments, depID);
//        dep_node = find_node(departments, depID);
//    }
//
//    dep_node->subTree = insert_emp_Node(dep_node->subTree, empID);
//}
