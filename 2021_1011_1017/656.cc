class Solution {
public:
    vector<int> cheapestJump(vector<int>& coins, int maxJump) {
        vector<int> ans;
        if (coins.back()==-1){
            return ans;
        }
        int n = coins.size();
        // dp[i]: the minimum cost from the (i+1)-th coin to the n-th coin
        vector<int> dp(n,100001);
        vector<int> path(n,-1);
        dp[n-1] = coins.back();
        for (int i=n-2; i>=0; --i){
            if (coins[i]==-1)   continue;
            for (int j=i+1; j<=min(n-1,i+maxJump); ++j){
                if (dp[j]==100001)  continue;
                if (dp[i]>dp[j]+coins[i]){
                    dp[i] = dp[j]+coins[i];
                    path[i] = j;
                } 
            }
        }
        //here, we cannot use path[0] to make decisions, since coins.length() may be 1
        if (dp[0]==100001){
            return ans;
        }
        int k=0;
        while (k!=-1){
            ans.push_back(k+1);
            k = path[k];
        }
        return ans;
    }
};
