class Solution {
public:
    int m,n;
    vector<int> dir = {-1,0,1,0,-1};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        queue<pair<int,int>> q;
        vector<vector<int>> ans(m,vector<int>(n,INT_MAX));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (mat[i][j]==0){
                    ans[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            for (int d=0; d<4; ++d){
                int xx = x + dir[d];
                int yy = y + dir[d+1];
                if (xx<0 || xx>=m || yy<0 || yy>=n) continue;
                if (ans[xx][yy]>ans[x][y]+1){
                    ans[xx][yy] = ans[x][y]+1;
                    q.push({xx,yy});
                }
            }
        }
        return ans;
    }
};
