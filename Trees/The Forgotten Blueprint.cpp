#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <queue>
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


int find_index(const vector<int>& inOrder, int preOrderValue, int inStart, int inEnd) {

    for (int i = inStart; i <= inEnd; i++) {
        if (inOrder[i] == preOrderValue) {
            return i;
        }
    }
    return -1;

}

Node* construct_tree(const vector<int>& preOrder, const vector<int>& inOrder, int inStart, int inEnd, int& preIndex) {

    if (inStart > inEnd) return nullptr;

    int index = find_index(inOrder, preOrder[preIndex], inStart, inEnd);
    Node* root = new Node(preOrder[preIndex]);
    preIndex++;
    if (inStart == inEnd) return root;
    

    root->left = construct_tree(preOrder, inOrder, inStart, index - 1, preIndex);
    root->right = construct_tree(preOrder, inOrder, index + 1, inEnd, preIndex);

    return root;
}


void print_BFS(Node* root) {
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
    int n;
    cin >> n;

    vector<int> preOrder(n);
    vector<int> inOrder(n);

    for (int i = 0; i < n; i++) {
        cin >> preOrder[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> inOrder[i];
    }


    Node* tree;
    int preIndex = 0;
    tree = construct_tree(preOrder, inOrder, 0, n - 1, preIndex);
    print_BFS(tree);




    return 0;
}
