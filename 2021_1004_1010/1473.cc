class Solution {
public:
    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(target+1, vector<int>(n+1, 1e8)));
        for (int i=1; i<=n; ++i){
            if (!houses.at(0)){
                dp[0][1][i] = cost[0][i-1];
            }
        }
        if (houses.at(0)){
            dp[0][1][houses.at(0)] = 0;
        }
        for (int i=1; i<m; ++i){
            for (int j=1; j<=target; ++j){
                
                if (!houses.at(i)){
                    // i has not been painted
                    for (int cur_col=1; cur_col<=n; ++cur_col){
                        dp[i][j][cur_col] = INT_MAX;
                        for (int pre_col=1; pre_col<=n; ++pre_col){
                            if (pre_col!=cur_col){
                                dp[i][j][cur_col] = min(dp[i][j][cur_col], dp[i-1][j-1][pre_col]+cost[i][cur_col-1]);
                            }else {
                                dp[i][j][cur_col] = min(dp[i][j][cur_col], dp[i-1][j][pre_col]+cost[i][cur_col-1]);
                            }
                        }   
                    }
                      
                }else {
                    // i has been painted
                    int cur_col = houses[i];
                    dp[i][j][cur_col] = dp[i-1][j][cur_col];
                    for (int pre_col=1; pre_col<=n; ++pre_col){
                        if (pre_col!=cur_col){
                            dp[i][j][cur_col] = min(dp[i][j][cur_col],dp[i-1][j-1][pre_col]);
                        }
                    }
                }
            }
        }
        int ans = *min_element(dp.back().back().begin(),dp.back().back().end());
        return ans>=1e8? -1 : ans;
    }
};
