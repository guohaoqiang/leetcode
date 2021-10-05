class Solution {
public:
    vector<int> rober(TreeNode* root){
        if (!root) return {0,0};
        vector<int> ans(2,0);
        vector<int> l = rober(root->left);
        vector<int> r = rober(root->right);
        
        ans.at(0) = max(l.at(0),l.at(1)) + max(r.at(0),r.at(1));
        ans.at(1) = l.at(0)+r.at(0)+root->val;
        
        return ans;
    }
    
    int rob(TreeNode* root) {
        
        vector<int> l = rober(root->left);
        vector<int> r = rober(root->right);
        
        int ans0 = max(l.at(0),l.at(1)) + max(r.at(0),r.at(1));
        int ans1 = l.at(0)+r.at(0)+root->val;
        return max(ans0,ans1);
    }
};
