class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void backtracking(int n, int k, int start){
        if (res.size()==k){
            ans.push_back(res);
            return ;
        }
        
        for (int i=start; i<=n; ++i){
            res.push_back(i);
            backtracking(n, k, i+1);
            res.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        backtracking(n, k, 1);
        return ans;
    }
};
