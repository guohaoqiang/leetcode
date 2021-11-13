class Solution {
public:
    // colID, rowID, nodes
    map<int,map<int,vector<int>>> mem;
    void dfs(TreeNode* root, int col, int row){
        if (!root)  return;
        mem[col][row].push_back(root->val);
        dfs(root->left, col-1, row+1);
        dfs(root->right, col+1, row+1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        dfs(root, 0, 0);
        vector<vector<int>> sol;
        for (auto col:mem){
            vector<int> tmp;
            for (auto row:col.second){
                for (auto e:row.second)
                    tmp.push_back(e);
            }
            sol.push_back(tmp);
        }
        return sol;
    }
};
