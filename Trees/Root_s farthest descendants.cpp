#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;


struct Node {
    int data, level;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }


};


void assign_level(Node* root, int level, int& maxLevel) {
    if (root == nullptr) return;
    level++;
    root->level = level;

    if (maxLevel < level) {
        maxLevel = level;
    }
    assign_level(root->left, level, maxLevel);
    assign_level(root->right, level, maxLevel);

}


void root_farthest_descendants(Node* root, int maxLevel, int& sum) {
    if(root == nullptr) return;

    if (root->level == maxLevel) {
        sum = sum + root->data;
    }

    root_farthest_descendants(root->left, maxLevel, sum);
    root_farthest_descendants(root->right, maxLevel, sum);
    return;
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
    int  parent, child;
    for (int i = 0; i < E; i++) {
        cin >> direction >> parent >> child;
        if (direction == 'L') {
            tree[parent]->left = tree[child];
        }
        else if (direction == 'R') {
            tree[parent]->right = tree[child];
        }
    }


    int level = 0;
    int maxLevel = -1;
    assign_level(tree[0], level, maxLevel);

    int sum = 0;
    root_farthest_descendants(tree[0], maxLevel, sum);
    
    cout << sum;


    return 0;
}
