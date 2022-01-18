class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char,int> m;
        for (auto c:t){
            m[c]++;
        }
        int ans = s.size() + 1;
        int count = 0;
        int i=0;
        int start = -1;
        for (int j=0; j<s.size(); ++j){
            if (--m[s[j]]>=0)  count++;   
            
            while (i<=j && count==t.size()){
                
                if (j-i+1<ans){
                    ans = j-i+1;
                    start = i;
                }
                
                if (++m[s[i]]>0){
                    count--;
                }
                
                i++;
            }
        }
        return ans==s.size()+1? "" : s.substr(start,ans);
    }
};
