//https://leetcode.com/problems/number-of-islands-ii/
class Solution {
public:
    int findp(vector<int>& root, int ch){
        while (root[ch]!=ch){
            ch = root[ch];
        }
        return ch;
    }
    vector<int> numIslands2(int m, int n, vector<vector<int>>& pos) {
        vector<int> root(m*n,-1);
        int ans = 0;
        vector<int> dir = {-1,0,1,0,-1};
        vector<int> sol;
        
        for (int i=0; i<pos.size(); ++i){
            int key = pos[i][0]*n + pos[i][1];
            if (root[key]!=-1){
                sol.push_back(ans);
                continue;
            }
            ans++;
            root[key] = key;
            for (int j=0; j<4; ++j){
                int x = pos[i][0] + dir[j];
                int y = pos[i][1] + dir[j+1];
                
                if (x<0 || x>=m || y<0 || y>=n || root[x*n+y]==-1) continue;
                int par = findp(root, x*n+y);
                if (par!=key){
                    root[key] = par;
                    key = par;
                    ans--;
                }
            }
            
            sol.push_back(ans);
        }
        return sol;
    }
};
