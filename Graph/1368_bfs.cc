//https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/discuss/524936/C%2B%2B-0-1-BFS-O(N)-instead-of-O(NlogN)
class Solution {
public:
    int dir[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    int minCost(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        
        deque<pair<int,int>> q;
        unordered_set<int> v;
        q.push_back(pair<int,int>(0,0));
        
        int ans = 0;
        while(!q.empty()){
            auto t = q.front();
            q.pop_front();
            int i = t.first/n, j = t.first%n;
            
            if (v.insert(t.first).second)   ans = t.second;
            if (i==m-1 && j==n-1)   return ans;
            
            for (int k=0; k<4; ++k){
                int x = i + dir[k][0];
                int y = j + dir[k][1];
                int pos  = x*n + y;
                if (x<0 || x>=m || y<0 || y>=n || v.count(pos))    continue;
                
                int cost = 1;
                if (grid[i][j]==1 && dir[k][0]==0 && dir[k][1]==1)  cost = 0;
                else if (grid[i][j]==2 && dir[k][0]==0 && dir[k][1]==-1) cost = 0;
                else if (grid[i][j]==3 && dir[k][0]==1 && dir[k][1]==0) cost = 0;
                else if (grid[i][j]==4 && dir[k][0]==-1 && dir[k][1]==0) cost = 0;
                
                if (cost)   q.push_back({pos,t.second+1});
                else    q.push_front({pos,t.second+0});
            }
            
        }
        return ans;
    }
};
