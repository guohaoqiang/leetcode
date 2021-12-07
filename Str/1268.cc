//Trie
class Solution {
public:
    
    class Trie{
    public:
        vector<Trie*> child{vector<Trie*>(26,nullptr)};
        bool isend=false;
    };
    
    void build(Trie* root, string& s){
        for (auto c:s){
            if (!root->child[c-'a']){
                root->child[c-'a'] = new Trie();
            }
            root = root->child[c-'a'];
        }
        root->isend = true;
    }
    void dfs(vector<string>& res, Trie* node, string& prefix){
        if (res.size()==3)  return;
        if (!node)  return;
        
        if (node->isend){
            res.push_back(prefix);
        }
        string s = prefix;
        for (int i=0; i<26; ++i){
            if (node->child[i]){
                s += (i+'a');
                dfs(res, node->child[i], s);
                s.pop_back();
            }
        }
    }
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        Trie* root = new Trie();
        // build the graph
        for (auto &w:products){
            build(root,w);
        }
        
        vector<vector<string>> ans;
        Trie* node = root;
        string s = "";
        for (auto c:searchWord){
            s += c;    
            vector<string> one;
            if(node && node->child[c-'a']){
                node = node->child[c-'a'];
                dfs(one, node, s);
            }else{
                break;
            }   
            ans.push_back(one);
        }
        while (ans.size()<searchWord.size())    ans.push_back({});
        return ans;
    }
};

//sort + binary search
class Solution {
public:
    vector<vector<string>> suggestedProducts(vector<string>& products, string searchWord) {
        sort(products.begin(),products.end());
        
        string s = "";
        auto it = products.begin();
        vector<vector<string>> ans;
        for (auto c:searchWord){
            s += c;
            it = lower_bound(it,products.end(),s);
            int cts = it - products.begin();
            vector<string> res;
            for (int i=cts; i<min(cts+3,(int)products.size()); ++i){
                if (products[i].find(s)!=-1){
                    res.push_back(products[i]);
                }
            }
            ans.push_back(res);
        }
        return ans;
    }
};
