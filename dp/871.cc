//https://leetcode.com/problems/minimum-number-of-refueling-stops/discuss/149839/DP-O(N2)-and-Priority-Queue-O(NlogN)
class Solution {
public:
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
        // (hops,dist)
        vector<long> dp(stations.size()+1,startFuel);
        for (int i=0; i<stations.size(); ++i){
            for (int j=i; j>=0 && dp[j]>=stations[i][0]; --j){
                dp[j+1] = max(dp[j+1], dp[j] + stations[i][1]);
            }
        }
        
        for (int i=0; i<dp.size(); ++i){
            if (dp[i]>=target){
                return i;
            }
        }
        return -1;
    }
};
