#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }
};


bool is_equal(vector<int> path, int K) {
    int sum = 0;
    for (int i = 0; i < path.size(); i++) {
        sum = sum + path[i];
    }

    if (sum == K) {
        return true;
    }
    return false;
}

void print_path(vector<int> path) {
    for (int i = 0; i < path.size(); i++) {
        cout << path[i] << " ";
    }
    cout << endl;
    return;
}


void tree_path_sum1(Node* root, vector<int> path, int N, int K) {
    
    if (!root) {
        return;
    }

    path.push_back(root->data);

    if (!root->left && !root->right) {
        if (is_equal(path, K)) {
            print_path(path);
        }
        return;
    }

    
    tree_path_sum1(root->left, path, N, K);
    tree_path_sum1(root->right, path, N, K);



    return;
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int K;
    cin >> K;

    int N;
    cin >> N;
    vector<Node*> tree(N);
    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        tree[i] = new Node(x);
    }

    int E;
    cin >> E;

    char direction;
    int parent, child;

    for (int i = 0; i < E; i++) {
        cin >> direction >> parent >> child;
        if (direction == 'L') {
            tree[parent]->left = tree[child];
        }
        else if (direction == 'R') {
            tree[parent]->right = tree[child];
        }
    }

    vector<int> path;
    tree_path_sum1(tree[0], path, N, K);


    return 0;
}
