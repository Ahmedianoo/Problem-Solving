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


//Node* insert(Node* root, int value) {
//    if (!root) return new Node(value);
//    if (value < root->data) root->left = insert(root->left, value);
//    else if (value > root->data) root->right = insert(root->right, value);
//    return root;
//}


Node* build(vector<int>& postOrder, int& index, int min, int max) {
    if (index < 0) return nullptr;

    int value = postOrder[index];
    if (value < min || value > max) return nullptr;

    Node* root = new Node(value);
    index--;

    root->right = build(postOrder, index, value, max);
    root->left = build(postOrder, index, min, value);
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

    vector<int> postOrder(N);

    for (int i = 0; i < N; i++) {
        cin >> postOrder[i];
    }
    int index = N - 1;
    Node* tree = build(postOrder, index, INT_MIN, INT_MAX);

    print(tree);



    return 0;
}
