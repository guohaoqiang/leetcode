class Solution {
public:
    vector<vector<int>> ans;
    vector<int> tmp;
    void dfs(TreeNode*& root){
        if (!root)  return;
        if (!root->left && !root->right){
            tmp.push_back(root->val);
            root = nullptr;
        }else{
            dfs(root->left);
            dfs(root->right);
        }
    }
    vector<vector<int>> findLeaves(TreeNode* root) { 
        while (root){
            dfs(root);
            ans.push_back(tmp);
            tmp.clear();
        }
        
        return ans;
    }
};
