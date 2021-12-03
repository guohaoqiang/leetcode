//https://leetcode.com/problems/word-search-ii/discuss/59841/My-AC-very-clean-C%2B%2B-code
class Solution {
public:
    class Trie{
    public:
        Trie* child[26] = {nullptr};
        int isend = false;
    };
    void insert(Trie* root, string& s){
        for (auto c:s){
            if (!root->child[c-'a']){
                root->child[c-'a'] = new Trie();
            }
            root = root->child[c-'a'];
        }
        root->isend = true;
    }
    Trie* head = new Trie();
    int m,n;
    vector<string> ans;
    unordered_set<string> st;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        for (int i=0; i<words.size(); ++i){
            insert(head,words[i]);
        }
        m = board.size(); n = board[0].size();
        
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                dfs(board, head, i, j, "");
            }
        }
        
        for (auto s:st){
            ans.push_back(s);
        }
        return ans;
    }
    
    void dfs(vector<vector<char>>& board, Trie* root, int i, int j, string s){
        if (i<0 || i>=m || j<0 || j>=n || board[i][j]=='*')  return ;
        
        if (root->child[board[i][j]-'a']){
            s += board[i][j];
            root = root->child[board[i][j]-'a'];
            if (root->isend)    st.insert(s);
            
            char  c = board[i][j];
            board[i][j] = '*';
            dfs(board, root, i+1, j, s); dfs(board, root, i-1, j, s);
            dfs(board, root, i, j+1, s); dfs(board, root, i, j-1, s);
            board[i][j] = c;
        }
    }
};
