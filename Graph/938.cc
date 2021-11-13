class Solution {
public:
    int ans = 0;
    int lb;
    int hb;
    void inorder(TreeNode* root){
        if (!root) return;

        inorder(root->left);
        if (root->val<=hb && root->val>=lb) {
            ans += root->val;
        }
        inorder(root->right);
    }
    int rangeSumBST(TreeNode* root, int low, int high) {
        lb = low;
        hb = high;
        inorder(root);
        return ans;
    }
};
