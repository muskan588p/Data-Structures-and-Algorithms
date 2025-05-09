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
    int leftheight(TreeNode* node){
        int h=0;
        while(node){
            h++;
            // leftheight(node->left);  
            node=node->left;  //update to next node to count nodes for left height
        }
        return h;
    }
    int rightheight(TreeNode* node){
        int h=0;
        while(node){
            h++;
            node=node->right;
        }
        return h;
    }
    int countNodes(TreeNode* root) {
        if(root==nullptr){
            return 0;
        }

        int lh=leftheight(root);
        int rh=rightheight(root);

        if(lh==rh){
            return (1 << lh)-1; //imp
        }

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};