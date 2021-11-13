class Solution {
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        //col ID, row ID, nodes
        map<int,map<int,vector<int>>> mem;
            
        queue<pair<vector<int>, TreeNode*>> q;
        // col ID, row ID, nodes 
        q.push({{0, 0}, root});
        while (!q.empty()){
            TreeNode* node = q.front().second;
            int col = q.front().first[0];
            int row = q.front().first[1];
            q.pop();
            mem[col][row].push_back(node->val);
            if (node->left) q.push({{col-1,row+1},node->left});
            if (node->right) q.push({{col+1,row+1},node->right});
        }
        
        vector<vector<int>> sol;
        for (auto cols:mem){
            vector<int> ans;
            for (auto row:cols.second){
                vector<int> tmp;
                for (auto node:row.second){
                    tmp.push_back(node);
                }
                sort(tmp.begin(),tmp.end());
                for (auto nd:tmp){
                    ans.push_back(nd);
                }
            }
            sol.push_back(ans);
        }
        
        return sol;
    }
};
