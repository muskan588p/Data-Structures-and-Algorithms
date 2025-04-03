/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void solve(TreeNode* root, vector<string>& ans, string curr){
        if(root==nullptr){
            return;
        }

        curr+=to_string(root->val);
        if(root->left==nullptr && root->right==nullptr){
            ans.push_back(curr);
        }

        curr += "->";

        solve(root->left, ans, curr);
        solve(root->right, ans, curr);

    }
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string curr="";

        solve(root, ans, curr);

        return ans;
    }
};