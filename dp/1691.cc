public:
    bool isValid(vector<int>& a, vector<int>& b){
        // if a can be put on b, return true
        if (a[0]<=b[0] && a[1]<=b[1] && a[2]<=b[2]){
            return true;
        }
        return false;
    }
    int maxHeight(vector<vector<int>>& cuboids) {
        for (auto &v:cuboids){
            sort(v.begin(),v.end());
        }
        sort(cuboids.begin(),cuboids.end());
        // the i-th cuboid is on the top
        vector<int> dp(cuboids.size(),0);
        
        int ans = 0;
        for (int i=0; i<cuboids.size(); ++i){
            dp[i] = cuboids[i][2];
            for (int j=0; j<i; ++j){
                if (isValid(cuboids[j],cuboids[i])){
                    dp[i] = max(dp[i], dp[j]+cuboids[i][2]);
                }
            }
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};
