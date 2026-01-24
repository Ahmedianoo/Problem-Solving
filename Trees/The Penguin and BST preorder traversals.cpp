#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
#include <climits>
using namespace std;



struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int value) {
        data = value;
        left = right = nullptr;
    }
};



Node* insert(Node* root, int value) {
    if (!root) return new Node(value);
    if (value < root->data) {
        root->left = insert(root->left, value);
    }
    else if (value > root->data) {
        root->right = insert(root->right, value);
    }

    return root;
}


Node* insert_node(const vector<int>& values, int& index, int min, int max, int N) {
    if (index == N) return nullptr;


    
    if (values[index] < min || values[index] > max) {
        return nullptr;
    }

    Node* root = new Node(values[index]);
    index++;
    root->left = insert_node(values, index, min, root->data, N);
    root->right = insert_node(values, index, root->data, max, N);

    return root;

}

void print(Node* root) {
    if (!root) return;
    queue<Node*> q;
    q.push(root);

    while (!q.empty()) {
        Node* curr = q.front();
        q.pop();
        cout << curr->data << " ";
        if (curr->left) q.push(curr->left);
        if (curr->right) q.push(curr->right);
    }
}




int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    vector<int> preOrder(N);
    for (int i = 0; i < N; i++) {
        cin >> preOrder[i];
    }

    int index = 0;
    
    Node* tree = insert_node(preOrder, index, INT_MIN, INT_MAX, N);

    print(tree);


    return 0;
}
