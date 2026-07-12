#include <iostream>
#include <queue>
#include <stack>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// dfs: recursion
int maxDepth(TreeNode* root) {
  if(!root) return 0;
  return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

// dfs: iterative, preorder
int maxDepth(TreeNode* root) {
  int level = 0;
  stack<pair<TreeNode*, int>> s;
  s.push({root, 1});

  while(!s.empty()){
    pair<TreeNode*, int> node = s.top();
    s.pop();

    level = max(level, node.second);

    if(node.first->left) s.push({node.first->left, node.second + 1});
    if(node.first->right) s.push({node.first->right, node.second + 1}); 
  }

  return level;
}

// bfs
int maxDepth(TreeNode* root) {
  if(!root) return 0;

  int level = 0;
  queue<TreeNode*> q;
  q.push(root);

  while(!q.empty()){
    int size = q.size();

    for(int i = 0; i < size; i++){
      TreeNode* node = q.front();
      q.pop();

      if(node->left) q.push(node->left);
      if(node->right) q.push(node->right); 
    }

    level++;
  }

  return level;
}
