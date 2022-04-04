class StreamChecker {
public:
    struct Trie{
        Trie* child[26]={nullptr};
        bool end = false;  
    };
    void insert(Trie* root, string& s){
        for (size_t i=1; i<s.size(); ++i){
            size_t pos = s[i] - 'a';
            if (!root->child[pos]){
                root->child[pos] = new Trie();
            }
            root = root->child[pos];  
        }
        root->end = true;
    }
    bool find(Trie* root, string& s){
        if (!root)  return false;
        if (root->end)  return true;
        for (size_t i=1; i<s.size(); ++i){
            if (!root->child[s[i]-'a'])  return false;
            if (root->child[s[i]-'a']->end)  return true;
            root = root->child[s[i]-'a'];
        }
        return false;
    }
    Trie* root[26]={nullptr};
    size_t l = 0;
    StreamChecker(vector<string>& words) {
        for (auto s:words){
            reverse(s.begin(), s.end());
            if (!root[s[0]-'a']){
                root[s[0]-'a'] = new Trie();
            }
            insert(root[s[0]-'a'], s);
            l = max(l, s.size());
        }
    }
    string mem;
    bool query(char letter) {
        mem = letter + mem;
        if (mem.size()>l)   mem = mem.substr(0,l);
        return find(root[letter-'a'], mem);
    }
};
