class Solution {
public:
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<vector<int>> task;
        
        for (int i=0; i<profit.size(); ++i){
            task.push_back({endTime[i],startTime[i],profit[i]});
        }
        sort(task.begin(),task.end());
        
        map<int,int> dp = {{0,0}};
        int ans = INT_MIN;
        for (int i=0; i<profit.size(); ++i){
            int cur = prev(dp.upper_bound(task[i][1]))->second + task[i][2];
            if (cur>dp.rbegin()->second){
                dp[task[i][0]] = cur;
            }
        }
        
        return dp.rbegin()->second;
    }
};
