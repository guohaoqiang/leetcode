class Solution {
public:
    int minCostII(vector<vector<int>>& costs) {
        int n = costs.size();
        int k = costs.at(0).size();
        vector<vector<int>> dp(n, vector<int>(k,2021));
        
        for (int i=0; i<k; ++i){
            dp.at(n-1).at(i) = costs.at(n-1).at(i);
        }
        
        
        for (int i=n-2; i>=0; --i){
            for (int j=0; j<k; ++j){
                for (int t=0; t<k; ++t){
                    if (j!=t){
                        dp.at(i).at(j) = min(dp.at(i+1).at(t)+costs.at(i).at(j), dp.at(i).at(j));
                    }
                }
            }
        }
        int ans = INT_MAX;
        for (int i=0; i<k; ++i){
            ans = min(ans,dp.at(0).at(i));
        }
        return ans;
    }
};
