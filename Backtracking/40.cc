class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void helper(vector<int>& c, int t, int start){
        if (t==0){
            ans.push_back(sub);
            return ;
        }
        if (t<1 || t>500)   return ;
        for (int i=start; i<c.size(); ++i){
            if (i>start && c[i]==c[i-1])    continue;
            sub.push_back(c[i]);
            t -= c[i];
            helper(c,t,i+1);
            sub.pop_back();
            t += c[i];
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        helper(candidates,target,0);
        return ans;
    }
};
