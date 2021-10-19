class Solution {
public:
    int mod = 1e9+7;
    int dfs(vector<int>& locations, int start, int finish, int fuel, vector<vector<int>>& dp){
        if (!dp[start][fuel]){
            dp[start][fuel] = 1 + (start==finish);
            for (int i=0; i<locations.size(); ++i){
                if (i!=start && fuel>=abs(locations[start]-locations[i])){
                    dp[start][fuel] = (dp[start][fuel] + dfs(locations, i, finish, fuel-abs(locations[start]-locations[i]), dp))%mod;
                }
            }
        }
        return dp[start][fuel]-1;
    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        vector<vector<int>> dp(n,vector<int>(fuel+1,0));  
        return dfs(locations, start, finish, fuel, dp);
    }
};
