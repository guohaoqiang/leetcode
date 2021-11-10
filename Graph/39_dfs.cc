class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void dfs(vector<int>& candidates, int sum, int start){
        if (sum<0){
            return ;
        }
        if (sum==0){
            ans.push_back(sub);
            return ;
        }
        
        for (int i=start; i<candidates.size(); ++i){
            sub.push_back(candidates[i]);
            sum -= candidates[i];
            dfs(candidates, sum, i);
            sum += candidates[i];
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        dfs(candidates, target, 0);
        return ans;
    }
};
