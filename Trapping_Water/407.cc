class Solution {
public:
    struct cmp{
        bool operator()(vector<int>& a, vector<int>& b){
            return a[0]>b[0];
        }
    };
    int trapRainWater(vector<vector<int>>& h) {
        int m = h.size();
        int n = h[0].size();
        priority_queue<vector<int>, vector<vector<int>>, cmp> pq;
        vector<vector<int>> tag(m,vector<int>(n,0));
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (!(i==0 || i==m-1 || j==0 || j==n-1))    continue;
                pq.push({h[i][j],i*n+j});
                tag[i][j] = 1;
            }
        }
        
        int sol = 0;
        int mx = 0;
        vector<vector<int>> dir = {{0,1},{1,0},{-1,0},{0,-1}};
        while (!pq.empty()){
            auto top = pq.top();
            pq.pop();
            mx = max(mx,top[0]);
            int xx = top[1]/n, yy = top[1]%n;
            for (int i=0; i<4; ++i){
                int x = xx + dir[i][0], y = yy + dir[i][1];
                if (x<0 || x>=m || y<0 || y>=n || tag[x][y]) continue;
                tag[x][y] = 1;
                pq.push({h[x][y],x*n+y});
                if (h[x][y]<mx){
                    sol += (mx-h[x][y]);
                }
            }
        }
        return sol;
    }
};
