class Solution {
public:
    void inorder(TreeNode* root, vector<int>& nodes) {
        if (root == nullptr) return;
        inorder(root->left, nodes);
        nodes.push_back(root->val);  // store sorted values
        inorder(root->right, nodes);
    }

    int kthSmallest(TreeNode* root, int k) {
        vector<int> nodes;
        inorder(root, nodes);
        return nodes[k - 1];  // kth smallest (1-indexed)
    }
};
