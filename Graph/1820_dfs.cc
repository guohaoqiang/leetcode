// https://leetcode.com/problems/maximum-number-of-accepted-invitations/discuss/1177540/JAVA-or-Maximum-Bipartite-Matching
class Solution {
public:
    int maximumInvitations(vector<vector<int>>& grid) {
        size_t m = grid.size();
        size_t n = grid[0].size();
        unordered_map<int, vector<int>> g;
        for (size_t i=0; i<m; ++i){
            for (size_t j=0; j<n; ++j){
                if (grid[i][j]){
                    g[i].push_back(j+m);
                    g[j+m].push_back(i);
                }
            }
        }
        int ans = 0;
        vector<int> matching(m+n,-1);
        for (size_t i=0; i<m; ++i){
            vector<bool> v(m+n, false);
            if (dfs(g, i, matching, v)){
                ans++;
            }
        }
        return ans;
    }
    bool dfs(unordered_map<int, vector<int>>& g, size_t r, vector<int>& matching, vector<bool>& v){
        for (size_t j=0; j<g[r].size(); ++j){
            if (!v[g[r][j]]){
                v[g[r][j]] = true;
                if (matching[g[r][j]]==-1 || dfs(g, matching[g[r][j]], matching, v)){
                    matching[g[r][j]] = r;
                    matching[r] = g[r][j];
                    return true;
                }
            }
        }
        return false;
    }
};
