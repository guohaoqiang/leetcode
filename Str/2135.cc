class Solution {
public:
    struct Trie{
        Trie* child[26] = {nullptr};
        bool isend = false;
        void insert(string& s, int p=0){
            int pos = s[p] - 'a';
            if (p<s.size()){
                if (!child[pos]){
                    child[pos] = new Trie();
                }
                child[pos]->insert(s, p+1);
            }else{
                isend = true;
            }
        }
        bool find(string& s, int p=0, bool skip=false){
            if (p==s.size())    return isend && skip;
            int idx = s[p] - 'a';
            
            return (child[idx]? child[idx]->find(s, p+1, skip): false) || 
                (skip? false : find(s, p+1, true));
        }
    };
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        Trie root;
        for (auto s:startWords){
            sort(s.begin(),s.end());
            root.insert(s);
        }
        
        int ans = 0;
        for (auto s:targetWords){
            sort(s.begin(),s.end());
            ans += root.find(s);
        }
        return ans;
    }
};
