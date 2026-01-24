#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

struct Node {
    int id;
    Node* left;
    Node* right;

    Node(int value) {
        id = value;
        left = nullptr;
        right = nullptr;
    }
};


void immortal_elders(Node* root, unordered_map<int, vector<int>>& children) {
    if (!root) return;
    if (root->left) children[root->id].push_back(root->left->id);
    if (root->right) children[root->id].push_back(root->right->id);

    immortal_elders(root->left, children);
    immortal_elders(root->right, children);
}


int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int M;
    std::cin >> M;
    int id;
    vector<int> eldersIDs(M);
    for (int i = 0; i < M; i++) {
        std::cin >> id;
        eldersIDs[i] = id;
    }


    int N;
    std::cin >> N;
    int x;
    vector<Node*> tree(N);
    
    for (int i = 0; i < N; i++) {
        std::cin >> x;
        tree[i] = new Node(x);
        
    }



    int E;
    std::cin >> E;
    char direction;
    int parent, child;
    for (int i = 0; i < E; i++) {
        std::cin >> direction >> parent >> child;
        if (direction == 'L') {
            tree[parent]->left = tree[child];
        }
        else if (direction == 'R') {
            tree[parent]->right = tree[child];
        }
        
    }

    unordered_map<int, vector<int>> children;
    immortal_elders(tree[0], children);




    for (int i = 0; i < M; i++) {
        if (children.find(eldersIDs[i]) != children.end()) {
            for (int j = 0; j < (int)children[eldersIDs[i]].size(); j++) {
                cout << children[eldersIDs[i]][j] << " ";
            }
            cout << endl;
        }
    }


    return 0;
}
