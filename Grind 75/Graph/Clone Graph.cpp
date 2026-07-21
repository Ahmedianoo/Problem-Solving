#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


class Node {
    public:
    int val;
    vector<Node*> neighbors;

    Node(){
        val = 0;
        neighbors = vector<Node*>();
    }

    Node(int _val){
        val = _val;
        neighbors = vector<Node*>();
    }

    Node(int _val, vector<Node*> _neighbors){
        val = _val;
        neighbors = _neighbors;
    } 
};

unordered_map<Node*, Node*> oldToNew;

Node* dfs(Node* node){
    if(oldToNew.count(node)) return oldToNew[node];

    Node* copy = new Node(node->val);
    oldToNew[node] = copy;

    for(Node* nei : node->neighbors){
        copy->neighbors.push_back(dfs(nei));
    }

    return copy;
}

// time: O(n), space: O(n)
Node* cloneGraph(Node* node) {
    if(node) return dfs(node);
    return nullptr;
}   