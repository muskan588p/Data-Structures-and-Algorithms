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
    int find(TreeNode* root, int& maxsum){
        if(root==nullptr){
            return 0;
        }

        int leftsum=max(find(root->left, maxsum), 0);
        int rightsum=max(find(root->right, maxsum) , 0);

        //root+left+right
        int currsum= leftsum + root->val + rightsum;  //if maxpathsum passes thorugh curr node

        maxsum=max(maxsum, currsum);

        return root->val + max(leftsum, rightsum); //either of left or right passes upward
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        find(root, maxsum);

        return maxsum;
    }
};