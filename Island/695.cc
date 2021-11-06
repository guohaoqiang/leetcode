// https://leetcode.com/problems/max-area-of-island/discuss/108533/JavaC%2B%2B-Straightforward-dfs-solution

class Solution {
public:
    int m,n;
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int ans = 0;
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]==1){
                    ans = max(ans,area(grid,i,j));
                }
            }
        }
        return ans;
    }
    
    int area(vector<vector<int>>& grid, int i, int j){
        if (i>=0 && i<m && j>=0 && j<n && grid[i][j]==1){
            grid[i][j]=0;
            return 1 + area(grid,i,j+1) + area(grid,i+1,j) + area(grid,i-1,j) + area(grid,i,j-1);
        }
        return 0;
    }
};
