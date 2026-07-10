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

int diameterOfBinaryTree(TreeNode* root) {
    int length = 0;
    getDiameter(root, length);
    return length;
}

int getDiameter(TreeNode* root, int& length){
    if(!root) return 0;

    int left = getDiameter(root->left, length);
    int right = getDiameter(root->right, length);

    length = max(length, left + right);

    return 1 + max(left, right);
}