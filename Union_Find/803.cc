//https://leetcode.com/problems/bricks-falling-when-hit/discuss/1505117/(C%2B%2B)-803.-Bricks-Falling-When-Hit

class Unionfind{
public:
    Unionfind(int n){
        parent.resize(n);
        iota(parent.begin(),parent.end(),0);
        //size.resize(n,1);
        size = vector<int>(n,1);
    }
    void connect(int i,int j){
        int ip = find(i);
        int jp = find(j);
        if (ip==jp)  return;
        if (size[ip]>size[jp])  swap(ip,jp);
        parent[ip] = jp;
        size[jp] += size[ip];
    }
    int find(int i){
        if (i!=parent[i]){
            parent[i] = find(parent[i]);
        }
        return parent[i];
    }
    int top(){
        return size[find(parent.size()-1)];
    }
private:
    vector<int> parent,size;
};
class Solution {
public:
    int dir[5] = {-1,0,1,0,-1};
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int m = grid.size(), n= grid[0].size();
        vector<vector<bool>> on(m,vector<bool>(n,false));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]) on[i][j] = true;
            }
        }
        for (int i=0; i<hits.size(); ++i){
            grid[hits[i][0]][hits[i][1]] = 0;
        }
        
        // update parent and size
        Unionfind uf(m*n+1);
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (grid[i][j]){
                    if (i==0) uf.connect(j,m*n);
                    for (int k=0; k<4; ++k){
                        int xx = i + dir[k];
                        int yy = j + dir[k+1];
                        if (xx>=0 && xx<m && yy>=0 && yy<n && grid[xx][yy]){
                            uf.connect(i*n+j,xx*n+yy);
                        }
                    }
                } 
            }
        }      
        //
        vector<int> ans;
        int prev = uf.top();
        for (int i=hits.size()-1; i>=0; --i){
            int x = hits[i][0];
            int y = hits[i][1];
            if (on[x][y]){
                grid[x][y] = 1;
                if (x==0)   uf.connect(y,m*n);
                for (int k=0; k<4; ++k){
                    int xx = x + dir[k];
                    int yy = y + dir[k+1];
                    if (xx>=0 && xx<m  && yy>=0 && yy<n && grid[xx][yy]){
                        uf.connect(x*n+y,xx*n+yy);
                    }
                }
                ans.push_back(max(0,uf.top()-prev-1));
                prev = uf.top();
            }else{
                ans.push_back(0);
            }
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
    
};
