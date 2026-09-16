#include <iostream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;


struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};


class Codec {
private:

    void dfs_serialize(TreeNode* root, string &result){
        if(!root) {
            result += "N,";
            return;
        }
            

        result += to_string(root->val) + ',';
        
        dfs_serialize(root->left, result);

        dfs_serialize(root->right, result);
    }

    TreeNode* dfs_deserialize(vector<string> &nums, int &i){
        if(nums[i] == "N"){
            i++;
            return nullptr;
        } 

        TreeNode* node = new TreeNode(stoi(nums[i]));
        i++;

        node->left = dfs_deserialize(nums, i);
        node->right = dfs_deserialize(nums, i);

        return node;
    }

    vector<string> dataToVec(string data){
        vector<string> nums;
        string curr = "";

        for(char c : data){
            if(c == ','){
                nums.push_back(curr);
                curr = "";
            } 
            else{
                curr += c;
            }
        }

        return nums;
    }   

    // vector<string> dataToVec(string data){
    //     vector<string> nums;
    //     string curr;
    //     stringstream ss(data);

    //     while(getline(ss, curr, ',')){
    //         nums.push_back(curr);
    //     }

    //     return nums;
    // }    
public:
    // time: O(n), space: O(n)
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result = "";

        dfs_serialize(root, result);

        return result;
    }

    // time: O(n), space: O(n)
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        vector<string> nums = dataToVec(data);
        int i = 0;
        return dfs_deserialize(nums, i);
    }
};