#include <iostream>

using namespace std;


struct TreeNode{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

//iterative
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
    TreeNode* curr = root;
    while(curr){
        if(p->val > curr->val && q->val > curr->val){
            curr = curr->right;
        }
        else if(p->val < curr->val && q->val < curr->val){
            curr = curr->left;
        }
        else return curr;
    } 
    return nullptr;
}

//recursive
// TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//     if(p->val > root->val && q->val > root->val){
//         return lowestCommonAncestor(root->right, p, q);
//     }  

//     if(p->val < root->val && q->val < root->val){
//         return lowestCommonAncestor(root->left, p, q);
//     }   
    
//     return root;
// }
