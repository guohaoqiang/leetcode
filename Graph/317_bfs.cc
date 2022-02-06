class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    int shortestDistance(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int total_h = 0;
        
        vector<vector<int>> t(m, vector<int>(n,0));
        int empty = 0;
        int ans = INT_MAX;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]==1){
                    int d = 0;
                    ans = INT_MAX;
                    // BFS
                    queue<pair<int,int>> q;
                    q.push({i,j});
                    while (!q.empty()){
                        int sz = q.size();
                        d++;
                        for (int k=0; k<sz; ++k){
                            auto top = q.front();
                            q.pop();
                        
                            for (int f=0; f<4; ++f){
                                int x = top.first + dir[f];
                                int y = top.second + dir[f+1];
                                if (x>=0 && x<m && y>=0 && y<n && grid[x][y]==empty){
                                    q.push({x,y});
                                    grid[x][y]--;
                                    t[x][y] += d;
                                    ans  = min(ans, t[x][y]);
                                }
                            } // end nb visit
                        }
                        
                    } // end BFS 
                    empty--;
                }
            }
        }
        return ans==INT_MAX ? -1: ans;
    }
};
