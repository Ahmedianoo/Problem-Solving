#include <iostream>
#include <unordered_map>

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

/*
here is what i am thinking of 

keep a hash map: key: rank, value: node value
at the end of the problem get the corresponding value for the required rank
an optimization, you are only interested in one rank only you do not need to save all those ranks


how would you do this
how to calculate the rank
the rank of this node (current node) is the count of nodes (above me + on my left + 1)


*/