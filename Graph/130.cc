class Solution {
public:
    int m,n;
    void bfs(vector<vector<char>>& b, int i, int j){
        
        queue<pair<int,int>> q;
        q.push({i,j});
        while (!q.empty()){
            auto top = q.front();
            q.pop();
            if (b[top.first][top.second]!='O')   continue;
            
            b[top.first][top.second]='E';
            if (top.first<m-1)  q.push({top.first+1,top.second});
            if (top.first>0)  q.push({top.first-1,top.second});
            if (top.second<n-1)  q.push({top.first,top.second+1});
            if (top.second>0)  q.push({top.first,top.second-1});
        }
    }
    void solve(vector<vector<char>>& board) {
        m = board.size();
        n = board[0].size();
        vector<pair<int,int>> help;
        for (int i=0; i<m; ++i){
            help.push_back({i,0});
            help.push_back({i,n-1});
        }
        for (int j=0; j<n; ++j){
            help.push_back({0,j});
            help.push_back({m-1,j});  
        }
        for (auto b:help){
            bfs(board, b.first, b.second);
        }
        
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (board[i][j]=='O'){
                    board[i][j] = 'X';
                }
                if (board[i][j]=='E'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};
