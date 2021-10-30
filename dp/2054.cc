//https://leetcode.com/problems/two-best-non-overlapping-events/discuss/1548965/C%2B%2B-or-with-explanation-or-Concise-or-DP

class Solution {
public:
    
    int maxTwoEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        map<int,int> dp;
        
        int ans = INT_MIN;
        int mx = 0;
        for (int i=events.size()-1; i>=0; --i){
            // find the event I can join in
            auto it = dp.upper_bound(events[i][1]);
            mx = max(mx,events[i][2]);
            dp[events[i][0]] = mx;
            
            if (it!=dp.end()){
                ans = max(ans,events[i][2]+(*it).second);
            }else{
                ans = max(mx,ans);
            }
       
        }
        return ans;
    }
};
