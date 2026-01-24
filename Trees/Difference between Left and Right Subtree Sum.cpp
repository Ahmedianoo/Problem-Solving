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
        left = right = nullptr;
    }
};


long long get_sum(Node* root, long long R, long long& count) {
    if (!root) return 0;

    long long left_sum = get_sum(root->left, R, count);
    long long right_sum = get_sum(root->right, R, count);

    if (abs(right_sum - left_sum) <= R) {
        count++;
    }

    return root->data + left_sum + right_sum;

}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    long long N, R;
    cin >> N >> R;

    vector<Node*> tree(N);
    int x;

    for (int i = 0; i < N; i++) {
        cin >> x;
        tree[i] = new Node(x);
    }

    //for (int i = 0; i < N; i++) {
    //    cout << tree[i]->data << " ";
    //}

    /*cout << endl;*/

    long long E;
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


    long long count = 0;

    get_sum(tree[0], R, count);

    cout << count;


    return 0;
}
