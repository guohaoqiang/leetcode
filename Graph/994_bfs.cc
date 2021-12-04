//https://leetcode.com/problems/rotting-oranges/discuss/588024/C%2B%2B-or-BFS-or-100-Space-95-time-or-explanation-of-logic
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int,int>> q;
        
        int fresh = 0;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]==2){
                    q.push(pair<int,int>(i,j));
                }
                if(grid[i][j]==1){
                    fresh++;
                }
            }
        }
        vector<int> dir = {-1,0,1,0,-1};
        int ans = -1;
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto top = q.front();
                q.pop();
                
                for (int j=0; j<4; ++j){
                    int x = top.first + dir[j];
                    int y = top.second + dir[j+1];
                    
                    if (x>=0 && x<m && y>=0 && y<n && grid[x][y]==1){
                        grid[x][y] = 2;
                        q.push(pair<int,int>(x,y));
                        fresh--;
                    }
                }
            }
            ans++;
        }
        
        if (fresh>0)    return  -1;
        if (ans==-1)    return  0;
        
        return ans;
    }
};

