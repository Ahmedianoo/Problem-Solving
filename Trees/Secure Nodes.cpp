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


void count_secure_nodes(Node* root, int max, int& count) {

    if (root == nullptr) {
        return;
    }


    if (max <= root->data) { //secure
        max = root->data;
        count++;
    }

    count_secure_nodes(root->left, max, count);
    count_secure_nodes(root->right, max, count);


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



    
    int count = 0;
    int max = -2147483647 - 1;


    count_secure_nodes(tree[0], max, count);

    cout << count;


    return 0;
}
