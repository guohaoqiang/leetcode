class AutocompleteSystem {
public:
    class cmp{
    public:
        bool operator()(pair<int,string>& a, pair<int,string>& b){
            // if they have the identical frequency
            if (a.first==b.first)   return a.second<b.second;
            // min-heap
            return a.first>b.first;
        }
    };
    struct Trie{
        Trie* child[27] = {nullptr};
        int freq = 0;
    };
    void insert(Trie* root, string& s, int f){
        int pos;
        for (size_t i=0; i<s.size(); ++i){
            if (s[i]==' ')   pos = 26;
            else    pos = s[i] - 'a';
            if (!root->child[pos]){
                root->child[pos] = new Trie();
            }
            root = root->child[pos];
        }
        // only the leaf accumulates the frequency
        root->freq += f;
    }
    void dfs(Trie* p, string s){
        if (!p) return ;
        
        if(p->freq) pq.push({p->freq, s});
        while (pq.size()>3){
            pq.pop();
        }
        
        char ch;
        for (size_t i=0; i<27; ++i){     
            if (p->child[i]){
                if (i<26)   ch = i + 'a';
                else    ch = ' ';
                dfs(p->child[i], s+ch);
            }    
        }
    }
      
    Trie* pr = new Trie();
    priority_queue<pair<int,string>, vector<pair<int,string>>, cmp> pq;
    string cur = "";
    AutocompleteSystem(vector<string>& sentences, vector<int>& times) {
        
        for (size_t i=0; i<sentences.size(); ++i){
            insert(pr, sentences[i], times[i]);
        }
    }
    Trie* cp = pr; // the current pointer
    vector<string> input(char c) {
        if (c=='#'){
            insert(pr, cur, 1);
            cur = "";
            cp = pr;
            return {};
        }
        cur += c;
        if (!cp){
            cp = nullptr;
            return {};
        }
        
    
        int pos;
        if (c==' ')   pos = 26;
        else    pos = c - 'a';
        cp = cp->child[pos];
        dfs(cp, cur);
        
        vector<string> ans;
        while (!pq.empty()) {
            auto top = pq.top();
            pq.pop();
            ans.insert(ans.begin(),top.second);
        }
        return ans;
    }
};

/**
 * Your AutocompleteSystem object will be instantiated and called as such:
 * AutocompleteSystem* obj = new AutocompleteSystem(sentences, times);
 * vector<string> param_1 = obj->input(c);
 */
