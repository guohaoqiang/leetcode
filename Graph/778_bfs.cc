// https://leetcode.com/problems/swim-in-rising-water/discuss/113765/PythonC%2B%2B-Binary-Search
class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int l = grid[0][0];
        int r = grid.size()*grid[0].size()-1;
        
        while (l<r){
            int m = (l+r)/2;
            if (check(m, grid)){
                r = m;
            }else{
                l = m+1;
            }
        }
        return l;
    }
    bool check(int m, vector<vector<int>>& grid){
        queue<pair<int,int>> q;
        q.push({0,0});
        unordered_set<int> v;
        v.insert(0);
        vector<int> dir = {-1,0,1,0,-1};
        while (!q.empty()){
            int x = q.front().first, y = q.front().second;
            q.pop();
            if (grid[x][y]<=m){
                if (x==grid.size()-1 && y==grid[0].size()-1)  return true;
                
                for (size_t k=0; k<4; ++k){
                    int xx = x+dir[k];
                    int yy = y+dir[k+1];
                    int key = xx*grid[0].size()+yy;
                    if (xx<0 || xx>=grid.size() || yy<0 || yy>=grid[0].size() || v.count(key))  continue;
                    q.push({xx,yy});
                    v.insert(key);
                }
            }
        
        }
        return false;
    }
};
