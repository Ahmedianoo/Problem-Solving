#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
using namespace std;


struct Node {
    int data, height, size, id;
    Node* left;
    Node* right;

    Node(int value, int id) {
        this->data = value;
        this->id = id;
        left = right = nullptr;
        height = 1;
        size = 1;
    }

};

int get_height(Node* root) {
    if (!root) return 0;
    return root->height;
}
int get_size(Node* root) {
    if (!root) return 0;
    return root->size;
}

int getBalance(Node* root) {
    if (!root) return 0;
    return get_height(root->left) - get_height(root->right);
}

Node* right_rotate(Node* current) {
    Node* new_current = current->left;
    Node* new_current_right = new_current->right;

    new_current->right = current;
    current->left = new_current_right;

    current->height = 1 + max(get_height(current->left), get_height(current->right));
    current->size = 1 + get_size(current->left) + get_size(current->right);

    new_current->height = 1 + max(get_height(new_current->left), get_height(new_current->right));
    new_current->size = 1 + get_size(new_current->left) + get_size(new_current->right);

    return new_current;
}


Node* left_rotate(Node* current) {
    Node* new_current = current->right;
    Node* new_current_left = new_current->left;

    new_current->left = current;
    current->right = new_current_left;

    current->height = 1 + max(get_height(current->left), get_height(current->right));
    current->size = 1 + get_size(current->left) + get_size(current->right);

    new_current->height = 1 + max(get_height(new_current->left), get_height(new_current->right));
    new_current->size = 1 + get_size(new_current->left) + get_size(new_current->right);
    return new_current;
}



Node* insert(Node* root, int value, int id) {
    if (!root) return new Node(value, id);
    if (value < root->data) root->left = insert(root->left, value, id);
    else if (value > root->data) root->right = insert(root->right, value, id);
    else {
        if (id < root->id) root->left = insert(root->left, value, id);
        else if (id > root->id) root->right = insert(root->right, value, id);
        else return root;
    }

    root->height = 1 + max(get_height(root->left), get_height(root->right));
    root->size = 1 + get_size(root->left) + get_size(root->right);

    int balance = get_height(root->left) - get_height(root->right);


    if (balance > 1 && value < root->left->data) {
        return right_rotate(root);
    }

    if (balance < -1 && value > root->right->data) {
        return left_rotate(root);
    }

    if (balance > 1 && value > root->left->data) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }

    if (balance < -1 && value < root->right->data) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }



    return root;
}

Node* min_value_node(Node* root) {
    Node* current = root;
    while (current->left) {
        current = current->left;
    }

    return current;
}

Node* delete_node(Node* root, int value, int id) {
    if (!root) return root;
    if (value < root->data) root->left = delete_node(root->left, value, id);
    else if (value > root->data) root->right = delete_node(root->right, value, id);
    else {

        if (id < root->id) root->left = delete_node(root->left, value, id);
        else if (id > root->id) root->right = delete_node(root->right, value, id);
        else {
            if (!root->left || !root->right) {// one child or no childs
                Node* temp = root->left ? root->left : root->right;
                if (!temp) {
                    temp = root;
                    root = nullptr;
                }
                else {
                    *root = *temp;
                }
                free(temp);
            }
            else {//two children case

                Node* temp = min_value_node(root->right);
                root->data = temp->data;
                root->id = temp->id;
                root->right = delete_node(root->right, temp->data, temp->id);

            }
        }
    }


    if (!root) return root;
    root->height = 1 + max(get_height(root->left), get_height(root->right));
    root->size = 1 + get_size(root->left) + get_size(root->right);

    int balance = get_height(root->left) - get_height(root->right);



    if (balance > 1 && getBalance(root->left) >= 0)
        return right_rotate(root);


    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = left_rotate(root->left);
        return right_rotate(root);
    }


    if (balance < -1 && getBalance(root->right) <= 0)
        return left_rotate(root);


    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = right_rotate(root->right);
        return left_rotate(root);
    }



    return root;

}



int get_rank(Node* root, int k) {
    if (!root) return -1;

    int right_size = get_size(root->right);
    if (right_size + 1 == k) return root->data;
    else if (right_size >= k) return get_rank(root->right, k);
    else return get_rank(root->left, k - right_size - 1);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int Q;
    cin >> Q;

    unordered_map<int, int> ids_to_scores;
    Node* root = nullptr;


    for (int i = 0; i < Q; i++) {
        string operation;
        cin >> operation;

        if (operation == "ADD") {
            int id, score;
            cin >> id >> score;
            if (ids_to_scores.count(id)) {
                root = delete_node(root, ids_to_scores[id], id);
            }
            root = insert(root, score, id);
            ids_to_scores[id] = score;
        }
        else if (operation == "REMOVE") {
            int id;
            cin >> id;
            if (ids_to_scores.count(id)) {
                root = delete_node(root, ids_to_scores[id], id);
                ids_to_scores.erase(id);
            }
        }
        else {
            int k;
            cin >> k;
            cout << get_rank(root, k) << endl;
        }
    }



    return 0;
}

