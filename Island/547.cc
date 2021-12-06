class Solution {
public:
    int findCircleNum(vector<vector<int>>& g) {
        int m = g.size();
        vector<int> v(m,0);
        int ans = 0;
        queue<int> q;
        for (int i=0; i<m; ++i){
            if (!v[i]){
                q.push(i);
                ans++;
                while (!q.empty()){
                    int top = q.front();
                    v[top] = 1;
                    q.pop();
                    for (int j=0; j<m; ++j){
                        if (g[top][j]==1 && !v[j]){
                            q.push(j);
                        }
                    }
                }
            }
        }
        
        return ans;
    }
};
