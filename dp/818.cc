// https://leetcode.com/problems/race-car/discuss/123834/JavaC%2B%2BPython-DP-solution
class Solution {
public:
    int dp[10001] = {0};
    int racecar(int t) {
        // terminate iteration
        if (dp[t]>0)  return dp[t];
        
        // n-bit
        int n = floor(log2(t)) + 1;
        if (1<<n == t+1){
            // 2^n-1 == t
            dp[t] = n;
        }else{
            // t < 2^n-1
            // t > 2^(n-1) - 1    very important
            // 0.....t.....2^n-1
            dp[t] = racecar((1<<n)-1-t) + n+1; // n A and 1 R 
            for (int i=0; i<n-1; ++i){
                // n-1 A , 1 R, i A, 1 R  = n+1+i steps
                dp[t] = min(dp[t], racecar(t - (1<<(n-1)) + (1<<i))+n+1+i);
            }
        }
        
        return dp[t];
    }
};
