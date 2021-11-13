class Solution {
public:
    int ans = INT_MIN;
    int dfs(TreeNode* root){
        if (!root)  return 0;
        int l = max(0,dfs(root->left));
        int r = max(0,dfs(root->right));
        int path = l + r + root->val;
        
        ans = max(ans, path);
        return max(l,r)+root->val;
    }
    
    int maxPathSum(TreeNode* root) {
        int sol = dfs(root);
        
        return ans;
    }
};
