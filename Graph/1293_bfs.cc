//https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/discuss/712992/C%2B%2B-or-BFS

class Solution {
public:
    int bfs(vector<vector<int>>& g, int k){
        vector<vector<int>> v(g.size(),vector<int>(g[0].size(),-1));
        queue<vector<int>> q;
        // (x,y,remaining elimination,path length)
        q.push({0,0,k,0});
        while (!q.empty()){
            auto cur = q.front();
            q.pop();
            if (cur[0]<0 || cur[0]>=g.size() || cur[1]<0 || cur[1]>=g[0].size()) continue;
            if (cur[0]==g.size()-1 && cur[1]==g[0].size()-1)    return cur[3];
            
            if (g[cur[0]][cur[1]]==1){
                if (cur[2]>0){
                    cur[2]--;
                }else{
                    continue;
                }
            }
            
            if (v[cur[0]][cur[1]]!=-1 && v[cur[0]][cur[1]]>=cur[2]) continue;
            
            v[cur[0]][cur[1]] = cur[2];
            
            q.push({cur[0]+1,cur[1],cur[2],cur[3]+1});
            q.push({cur[0]-1,cur[1],cur[2],cur[3]+1});
            q.push({cur[0],cur[1]+1,cur[2],cur[3]+1});
            q.push({cur[0],cur[1]-1,cur[2],cur[3]+1});
        }
        return -1;
    }
    int shortestPath(vector<vector<int>>& grid, int k) {
        return bfs(grid,k);
    }
};
