#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;


struct Node{
    int data;
    Node* left;
    Node* right;

    Node(int value) {
        data = value;
        left = nullptr;
        right = nullptr;
    }

};



void the_royal_garden_of_binary_trees(Node* root) {
    if (!root) return;

    queue<Node*> q;

    q.push(root);

    while (!q.empty()) {
        int size = q.size();

        
        vector<int> current_level;
        

        for (int i = 0; i < size; i++) {
            Node* curr = q.front();
            q.pop();
            current_level.push_back(curr->data);
            if (curr->left) q.push(curr->left);
            if (curr->right) q.push(curr->right);
        }


        vector<int> sorted_tree = current_level;
        sort(sorted_tree.begin(), sorted_tree.end());

        int misPlaced = 0;
        for (int i = 0; i < (int)sorted_tree.size(); i++) {
            if (sorted_tree[i] != current_level[i]) {
                misPlaced++;
            }
        }

        cout << misPlaced << endl;
        
    }


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


    the_royal_garden_of_binary_trees(tree[0]);

    


    return 0;
}
