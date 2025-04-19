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
    int findpos(vector<int>& inorder, int ele, int n){
        for(int i=0;i<n;i++){
            if(inorder[i] == ele){
                return i;   //index
            }
        }
        return -1;
    } 
    //pass the pridx by reference
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder, int& preidx, int instart, int inend, int n) {
        //base case
        if(preidx >= n || instart > inend){
            return nullptr;
        }

        int ele=preorder[preidx++];  //increment index
        TreeNode* root = new TreeNode(ele);
        int pos = findpos(inorder, ele, n);

        //recursive calls
        root->left= solve(preorder, inorder, preidx, instart, pos-1, n);
        root->right= solve(preorder, inorder, preidx, pos+1, inend, n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n=preorder.size();
        int preidx=0;
        TreeNode* ans=solve(preorder, inorder, preidx, 0, n-1, n);//instart, inend, size
        return ans;
    }
};