class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void dfs(vector<int>& candi, int start, int sum){
        if (sum<0)  return ;
        if (sum==0){
            ans.push_back(sub);
            return ;
        }
        
        int len = candi.size();
        for (int i=start; i<len; ++i){
            if (i>start && candi[i]==candi[i-1])   continue;
            sub.push_back(candi[i]);
            sum -= candi[i];
            dfs(candi,i+1,sum);
            sum += candi[i];
            sub.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum2(vector<int>& candi, int target) {
        sort(candi.begin(),candi.end());
        dfs(candi, 0, target);
        
        return ans;
    }
};
