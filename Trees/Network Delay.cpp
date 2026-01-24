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



int height(Node* root, int& maxDelay) {
    if (root == nullptr) {
        return 0;
    }

    int leftHeight = height(root->left, maxDelay);
    int rightHeight = height(root->right, maxDelay);

    maxDelay = max(maxDelay, leftHeight + rightHeight);

    return 1 + max(leftHeight, rightHeight);
}



int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int N;
    cin >> N;
    int x;
    vector<Node*> tree(N);
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
        } else if(direction == 'R') {
            tree[parent]->right = tree[child];
        }
    }

    int maxDelay = 0;

    height(tree[0], maxDelay);

    cout << maxDelay;

    return 0;
}
