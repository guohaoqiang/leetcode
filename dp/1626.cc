class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        vector<vector<int>> players;
        for (int i=0; i<scores.size(); ++i){
            players.push_back({ages[i],scores[i]});
        }
        sort(players.begin(),players.end(),greater<>());
        
        // end with the i-th player
        vector<int> dp(scores.size(),0);
        
        for (int i=0; i<scores.size(); ++i){
            dp[i] = players[i][1];
            for (int j=0; j<i; ++j){
                if (players[i][1]<=players[j][1]){
                    dp[i] = max(dp[i],dp[j]+players[i][1]);
                }
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};
