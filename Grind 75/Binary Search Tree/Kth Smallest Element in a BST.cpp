#include <iostream>
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


// iterative
// time: O(H + K), space: O(H)
int kthSmallest(TreeNode* root, int k) {
    int n = 0;
    TreeNode *curr = root;
    stack<TreeNode*> st;

    while(curr || !st.empty()){
        while(curr){
            st.push(curr);
            curr = curr->left;
        }
        curr = st.top();
        st.pop();
        n++;
        if(n == k) return curr->val;

        curr = curr->right;
    }

    return -1;
}

// recursive
// time: O(H + K), space: O(H)
int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    
    return inorder(root, count, k);
}

int inorder(TreeNode* node, int &count, int k){
    if(!node) return - 1;

    int left = inorder(node->left, count, k);
    if(left != -1) return left;

    count++;
    if(count == k){
        return node->val;
    }

    return inorder(node->right, count, k);
}

int kthSmallest(TreeNode* root, int k) {
    int count = 0;
    int answer;
    
    inorder(root, count, answer, k);

    return answer;
}

void inorder(TreeNode* node, int &count, int &answer, int k){
    if(!node) return;

    inorder(node->left, count, answer, k);

    count++;
    if(count == k){
        answer = node->val;
        return;
    }

    inorder(node->right, count, answer, k);
}