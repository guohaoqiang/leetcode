class Solution {
public:
    int mod = 1e9+7;
    vector<int> pathsWithMaxScore(vector<string>& board) {
        int m = board.size();
        int n = board[0].size();
        board[0][0] = board[m-1][n-1] = '0';
        vector<vector<int>> dir = {{1,0},{1,1},{0,1}};
        vector<vector<int>> dp_paths(m,vector<int>(n,0));
        vector<vector<int>> dp_weight(m,vector<int>(n,0));
        dp_paths[m-1][n-1] = 1;
        dp_weight[m-1][n-1] = 0;
        for (int i=m-1; i>=0; --i){
            for (int j=n-1; j>=0; --j){
                if (board[i][j]=='X' || (i==m-1 && j==n-1)){
                    continue;
                }
                if (i==m-1 && j<n-1){
                    dp_paths[i][j] = dp_paths[i][j+1];
                    dp_weight[i][j] = dp_weight[i][j+1]+board[i][j]-'0';
                    continue;
                }
                if (j==n-1 && i<m-1){
                    dp_paths[i][j] = dp_paths[i+1][j];
                    dp_weight[i][j] = dp_weight[i+1][j]+board[i][j]-'0';
                    continue;
                }
                for (auto d:dir){
                    int x = i+d[0];
                    int y = j+d[1];
                    int val = dp_weight[x][y] + board[i][j]-'0';
                    if (dp_weight[i][j]<=val && dp_paths[x][y]){
                        dp_paths[i][j] = ((dp_weight[i][j]==val? dp_paths[i][j] : 0) + dp_paths[x][y])%mod;
                        dp_weight[i][j] = val;
                    }
                }
            }
        }
        
        return {dp_paths[0][0]>0?dp_weight[0][0]:0,dp_paths[0][0]};
    }
};
