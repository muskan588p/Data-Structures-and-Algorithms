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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int& postidx, int instart, int inend, int n, map<int, int>& mp){
        //base case
        if(postidx < 0 || instart > inend){
            return nullptr;
        }

        int ele = postorder[postidx--];
        TreeNode* root=new TreeNode(ele);
        int pos= mp[ele];

        //recursive calls
        root->right=solve(inorder, postorder, postidx, pos+1, inend, n, mp);
        root->left=solve(inorder, postorder, postidx, instart, pos-1, n, mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n=inorder.size();
        map<int, int> mp;

        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]] = i;
        }
        int postidx=n-1;
        TreeNode* ans=solve(inorder, postorder, postidx, 0, n-1, n, mp);

        return ans;
    }
};