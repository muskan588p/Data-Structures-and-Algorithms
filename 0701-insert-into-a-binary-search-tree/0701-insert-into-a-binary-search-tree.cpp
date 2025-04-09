class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        // If the root is null, we create and return a new node
        if (root == nullptr) {
            return new TreeNode(val);
        }

        // If the value is less than root's value, insert into the left subtree
        if (val < root->val) {
            root->left = insertIntoBST(root->left, val);
        }
        // If the value is greater than root's value, insert into the right subtree
        else {
            root->right = insertIntoBST(root->right, val);
        }

        return root;
    }
};
