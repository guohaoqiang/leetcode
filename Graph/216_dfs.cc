class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void dfs(int start, int k, int n){
        int nums[9] = {1,2,3,4,5,6,7,8,9};
        
        if (n<0 || (n==0 && k>0))    return ;    
        if (n==0 && k==0){
            ans.push_back(sub);
            return ;
        }
        for (int i=start; i<min(9,n); ++i){
            sub.push_back(nums[i]);
            n -= nums[i];
            dfs(i+1, k-1, n);
            n += nums[i];
            sub.pop_back();
        }
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        dfs(0, k, n);
        return ans;
    }
};
