#include <iostream>
#include <vector>
#include <queue>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
   TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n), space: O(h), bfs
vector<int> rightSideView(TreeNode* root) {
    if(!root) return {};
    queue<TreeNode*> q;
    q.push(root);
    vector<int> result;

    while(!q.empty()){
        int size = q.size();

        result.push_back(q.front()->val);
        for(int i = 0; i < size; i++){
            TreeNode *node =  q.front();
            q.pop();

            if(node->right) q.push(node->right);
            if(node->left) q.push(node->left);
        }
    }

    return result;
}

// time: O(n), space: O(h), bfs 
void dfs(TreeNode* node, int depth, vector<int>& result) {
    if (!node) return;

    if (depth == result.size()) {
        result.push_back(node->val);
    }

    dfs(node->right, depth + 1, result);
    dfs(node->left, depth + 1, result);
}

vector<int> rightSideView(TreeNode* root) {
    vector<int> result;
    dfs(root, 0, result);
    return result;
}