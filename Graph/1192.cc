class Solution {
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        unordered_map<int,vector<int>> mp;
        vector<int> dist(n,0);
        vector<int> low(n,0);
        for (auto c:connections){
            mp[c[0]].push_back(c[1]);
            mp[c[1]].push_back(c[0]);
        }
        vector<vector<int>> ans;
        dfs(ans, mp, dist, low, 0, -1);
        return ans;
    }
    int time = 1;
    void dfs(vector<vector<int>>& ans, unordered_map<int,vector<int>>& mp, vector<int>& dist, vector<int>& low, int cur, int prev){
        dist[cur] = low[cur] = time++;
        for (auto nb:mp[cur]){
            if (dist[nb] == 0){
                // nb node has not been visited
                dfs(ans, mp, dist, low, nb, cur);
                low[cur] = min(low[cur],low[nb]);
            }else if (nb!=prev){
                low[cur] = min(low[cur],dist[nb]);
            }
            if (low[nb]>dist[cur]){
                ans.push_back({cur,nb});
            }
        }
    }
};

