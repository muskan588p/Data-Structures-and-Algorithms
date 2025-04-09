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
    TreeNode* findMin(TreeNode* node) {
        while (node->left != nullptr) {
            node = node->left;
        }
        return node;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==nullptr){
            return root;
        }

        if(root->val == key){
            //0 child  
            if(root->left == nullptr && root->right == nullptr){   //leaf node
                delete root;
                return nullptr;
            } 
            //1 child
            //left exists
            if(root->left != nullptr && root->right == nullptr){
                TreeNode* temp=root->left;
                delete root;
                return temp;
            }
            //right exists
            if(root->left == nullptr && root->right != nullptr){
                TreeNode* temp=root->right;
                delete root;
                return temp;
            }
            //2 child
            if(root->left != nullptr && root->right !=nullptr){
                TreeNode* minNode = findMin(root->right); // Inorder successor
                root->val = minNode->val;
                root->right = deleteNode(root->right, minNode->val);
            }            
        }

        if(root->val > key){
            root->left=deleteNode(root->left, key);
            return root;
        }
        else{
            root->right=deleteNode(root->right, key);
            return root;
        }
        return root;
    }
};