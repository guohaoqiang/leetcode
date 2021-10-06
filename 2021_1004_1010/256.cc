class Solution {
public:
    int minCost(vector<vector<int>>& costs) {
        int n = costs.size();
        
        vector<vector<int>> dp(n,vector<int>(3,0));
        
        for (int i=0; i<3; ++i){
            dp.at(n-1).at(i) = costs.at(n-1).at(i);
        }
        
        for (int i=n-2; i>=0; --i){
            dp.at(i).at(0) = min(dp.at(i+1).at(1),dp.at(i+1).at(2))+costs.at(i).at(0);
            dp.at(i).at(1) = min(dp.at(i+1).at(0),dp.at(i+1).at(2))+costs.at(i).at(1);
            dp.at(i).at(2) = min(dp.at(i+1).at(0),dp.at(i+1).at(1))+costs.at(i).at(2);
        }
        
        int ans = INT_MAX;
        for (int i=0; i<3; ++i){
            ans = min(ans, dp.at(0).at(i));
        }
        
        return ans;
    }
};
