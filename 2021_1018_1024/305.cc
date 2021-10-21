class Solution {
public:
    int findRoot(vector<int>& roots, int chld){
        while (roots[chld]!=chld){
            chld = roots[chld];
        }
        return chld;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& positions) {
        int len = positions.size();
        vector<vector<int>> dir{{0,1},{1,0},{0,-1},{-1,0}};
        vector<int> ans(len,0);
        vector<int> roots(m*n,-1);
        
        int count = 0;
        for (int i=0; i<len; ++i){
            int p = positions[i][0]*n + positions[i][1];
            
            if (roots[p]!=-1){
                ans[i] = count;
                continue;
            }   
   
            count++;
            roots[p] = p;
            for (int j=0; j<4; ++j){
                int x = positions[i][0] + dir[j][0];
                int y = positions[i][1] + dir[j][1];
                if (x<0 || x>=m || y<0 || y>=n || roots[x*n+y]==-1)  continue;
                int par = findRoot(roots,x*n+y);
                if (p!=par){
                    roots[p] = par;
                    p = par;
                    count--;
                }
            }
            ans[i] = count;
        }
        
        return ans;
    }
};
