//https://leetcode.com/problems/prefix-and-suffix-search/discuss/1570239/C%2B%2B-JUST-SMALL-MODIFY-TRIE-INSERT-AND-SEARCH-SO-NEAT
class WordFilter {
public:
    class Trie{
    public:
        Trie* child[27] = {nullptr};
        int idx;
    };
    Trie* root = new Trie();
    void insert(string s, int id){
        Trie* node = root;
        for (auto c:s){
            if (!node->child[c-'a']){
                node->child[c-'a'] = new Trie();
            }
            node = node->child[c-'a'];
            node->idx = id;
        }
    }
    WordFilter(vector<string>& w) {
        for (int i = 0; i<w.size(); ++i){
            string word = w[i];
            string suf = "";
            for (int j=word.size()-1; j>=0; --j){
                suf = word[j] + suf;
                string toinsert = suf + "{" + word;
                insert(toinsert,i);
            }
        }
    }
    int dfs(string s){
        Trie* node = root;
        if (!node)  return -1;
        for (auto c:s){
            node = node->child[c-'a'];
            if (!node)  return -1;
        }
        
        return node->idx;
    }
    int f(string prefix, string suffix) {
        string temp = suffix + "{" + prefix;
        return dfs(temp);
    }
};
