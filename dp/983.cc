class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& c) {
        unordered_set<int> st(days.begin(),days.end());
        vector<int> dp(30,0);
        for (int i=days[0]; i<=days.back(); ++i){
            if (st.count(i)){
                dp[i%30] = min(dp[(i-1)%30]+c[0], min(dp[max(0,i-7)%30]+c[1], dp[max(0,i-30)%30]+c[2]));
            }else{
                dp[i%30] = dp[(i-1)%30];
            }
        }
        return dp[days.back()%30];
    }
};
