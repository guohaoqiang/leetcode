class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        if (k==0 || n>=maxPts+k-1)  return 1.0;
        
        vector<double> dp(n+1,0);
        dp[0] = 1;
        double wsum = 1.0;
        double ans = 0.0;
        for (int i=1; i<=n; ++i){
            dp[i] = wsum/maxPts;
            // p(i) = (p(i-1) + p(i-2) + ... + p(i-maxPoints))/maxPts
            if (i<k){
                wsum += dp[i];
            }else {
                ans += dp[i];
            }
            if (i>=maxPts){
                wsum -= dp[i-maxPts];
            }
        }
        return ans;
    }
};
