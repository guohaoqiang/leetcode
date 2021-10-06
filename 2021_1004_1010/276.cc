class Solution {
public:
    int numWays(int n, int k) {
        if (n==1)   return k;
        if (n==2)   return k*k;
        
        vector<int> dp(n,0);
        dp.at(0) = k;
        dp.at(1) = k*k;
        
        for (int i=2; i<n; ++i){
            dp.at(i) = (k-1)*dp.at(i-1) + (k-1)*dp.at(i-2);
        }
        
        return dp.back();
    }
};
