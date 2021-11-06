class Solution {
public:
    string alienOrder(vector<string>& words) {
        
        string ans = "";
        unordered_set<char> chars;
        unordered_map<char,unordered_set<char>> pre,suc;
        string s;
        for (auto t:words){
            chars.insert(t.begin(),t.end());
            if (s.size()>t.size() && s.substr(0,t.size())==t)   return ans;
            int sz = min(s.size(),t.size());
            for (int i=0; i<sz; ++i){
                if (s[i]!=t[i]){
                    suc[s[i]].insert(t[i]);
                    pre[t[i]].insert(s[i]);
                    break;
                }
            }
            s = t;
        }
        
        unordered_set<char> free = chars;
        for (auto& it:pre){
            free.erase(it.first);
        }
        // now, free only contains one root character
        
        while (!free.empty()){
            char a = *free.begin();
            free.erase(a);
            ans += a;
            for (auto b:suc[a]){
                pre[b].erase(a);
                if (pre[b].empty()){
                    free.insert(b);
                }
            }
        }
        
        return ans.size()==chars.size()? ans: "";
    }
    
};
