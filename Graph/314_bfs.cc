class Solution {
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> sol;
        map<int,vector<int>> mem;
        if (!root)  return sol;
        queue<pair<int,TreeNode*>> q;
        q.push({0,root});
        
        while (!q.empty()){
            TreeNode* node = q.front().second;
            int col = q.front().first;
            q.pop();
            mem[col].push_back(node->val);
            
            if (node->left){
                q.push({col-1,node->left});
            }
            if (node->right){
                q.push({col+1,node->right});
            }
        }
        
        
        for (auto v:mem){
            sol.push_back(v.second);
        }
        
        return sol;
    }
};
