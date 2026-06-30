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


// O(n)
bool isBalanced(TreeNode* root) {
    return checkHeight(root) != -1;
}

int checkHeight(TreeNode* root){
    if(!root) return 0;

    int leftHeight = checkHeight(root->left);
    if(leftHeight == -1) return -1;

    int rightHeight = checkHeight(root->right);
    if(rightHeight == -1) return -1;

    if(abs(rightHeight - leftHeight) > 1) return -1;
    
    return 1 + max(leftHeight, rightHeight);
}

// O(n^2)
// bool isBalanced(TreeNode* root) {
//     if(!root) return true;

//     return abs(getHeight(root->left) - getHeight(root->right)) <= 1 
//         && isBalanced(root->left) 
//         && isBalanced(root->right);
// }

// int getHeight(TreeNode* root){
//     if(!root) return 0;
//     return 1 + max(getHeight(root->left), getHeight(root->right));
// }