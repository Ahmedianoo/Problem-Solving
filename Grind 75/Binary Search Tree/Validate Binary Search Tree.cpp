#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// time: O(n), space: O(h), (O(log n) balanced, O(n) worst case)
TreeNode* previous  = nullptr;

bool isValidBST(TreeNode* root) {
    if(!root) return true;

    if(!isValidBST(root->left)) return false;


    if(previous  && root->val <= previous ->val) return false;

    previous  = root;

    return isValidBST(root->right);
}

// time: O(n), space: O(h), (O(log n) balanced, O(n) worst case)
bool isValidBST(TreeNode* root) {
    return valid(root, LLONG_MIN, LLONG_MAX);
}

bool valid(TreeNode* root, long long low, long long high){
    if(!root) return true;
    
    if(root->val <= low || root->val >= high) return false;
    
    return valid(root->left, low, root->val) && valid(root->right, root->val, high);
}