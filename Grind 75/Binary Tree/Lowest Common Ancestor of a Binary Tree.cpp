#include <iostream>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// time: O(n), space: O(h)
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    if(!root || root == p || root == q) return root;

    TreeNode* left = lowestCommonAncestor(root->left, p, q);
    TreeNode* right = lowestCommonAncestor(root->right, p, q);

    if(right && left) return root;
    return left ? left : right;
}

// the problem here that we cannot depend just on value to go to make the decision
// we have a case, when the root is equal to one of them, it is the ans, need to be put in the right place
// we it is not we go left and right 
// the solution is the root of the subtree that contain both of them, so how can we detect it
// we cannot add something to the node itself
// we search for the two numbers in the left and right subtrees
// if one is find on the left, and the other on the right, this is the solution
// if one side of them do not find any of them, then is is not the solution, and we go deeper to the side were we found both
// so, we search for them on the right and left side, if the returned value is not null then we found them