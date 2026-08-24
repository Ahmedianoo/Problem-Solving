#include <iostream>
#include <vector>
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

// time: O(n), space: O(n)
unordered_map<int, int> inorderIndex;

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    for (int i = 0; i < inorder.size(); i++) {
        inorderIndex[inorder[i]] = i;
    }    
    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
    int preStart, int preEnd,
    int inStart, int inEnd
    ) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    int nodeVal = preorder[preStart];
    TreeNode* node = new TreeNode(nodeVal);

    int i = inorderIndex[nodeVal];
    int leftSize = i - inStart;

    node->left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + leftSize, inStart, i - 1);
    node->right = buildTreeHelper(preorder, inorder, preStart + leftSize + 1, preEnd, i + 1, inEnd);

    return node;
}

// time: O(n ^ 2), space: O(n)
TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
    return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
}

TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, 
    int preStart, int preEnd,
    int inStart, int inEnd
    ) {
    if (preStart > preEnd || inStart > inEnd) return nullptr;

    int nodeVal = preorder[preStart];
    TreeNode* node = new TreeNode(nodeVal);

    int i = inStart;
    while(inorder[i] != nodeVal){
        i++;
    }

    int leftSize = i - inStart;

    node->left = buildTreeHelper(preorder, inorder, preStart + 1, preStart + leftSize, inStart, i - 1);
    node->right = buildTreeHelper(preorder, inorder, preStart + leftSize + 1, preEnd, i + 1, inEnd);

    return node;
}

