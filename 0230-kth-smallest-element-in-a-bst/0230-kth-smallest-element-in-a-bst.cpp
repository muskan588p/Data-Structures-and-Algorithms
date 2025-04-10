class Solution {
public:
    int inorder(TreeNode* root,int k, int& count, int& ans) {
        if (root == nullptr){
            return -1;
        }
        inorder(root->left, k, count, ans);
        count++;
        if(count == k){
            ans=root->val;
            return ans;
        }
        inorder(root->right, k, count, ans);

        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int count=0;
        int ans=-1;
        inorder(root, k, count, ans);
        return ans;
    }
};
