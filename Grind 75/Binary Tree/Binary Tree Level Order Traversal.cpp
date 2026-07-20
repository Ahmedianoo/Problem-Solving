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

// time: O(n), space: O(n)
vector<vector<int>> levelOrder(TreeNode* root) {
    if(!root) return {};

    queue<TreeNode*> q;
    q.push(root);
    vector<vector<int>> result;

    while(!q.empty()){
        result.push_back({});
        int size = q.size();
        
        for(int i = 0; i < size; i++){
            TreeNode* node = q.front();
            q.pop();

            result.back().push_back(node->val);

            if(node->left) 
                q.push(node->left);

            if(node->right) 
                q.push(node->right);
        }
    }

    return result;
}
