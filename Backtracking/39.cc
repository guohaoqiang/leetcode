class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void helper(vector<int>& c, int t, int start){
        if (t==0){
            ans.push_back(sub);
            return;
        }
        if (t<1 || t>500)    return ;
        for (int i=start; i<c.size(); ++i){
            t -= c[i];
            sub.push_back(c[i]);
            helper(c,t,i);
            t += c[i];
            sub.pop_back();
        }
        
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        helper(candidates,target,0);
        return ans;
    }
};
