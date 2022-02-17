class Solution {
public:
    string reorganizeString(string s) {
        vector<int> mp(26,0);
        char cc;
        int mx = 0;
        for (char c:s){
            if (++mp[c-'a']>mx){
                cc = c;
                mx = mp[c-'a'];
            }
            if (mx>(s.size()+1)/2)   return "";
        }
        
        string ss(mx,cc);
        for (int i=0; i<26; ++i){
            if (i!=cc-'a'){
                while (mp[i]--){
                    ss += (i+'a');
                }
            }
        }
        
        string ans;
        for (int i=0, j=(s.size()+1)/2; i<(s.size()+1)/2; ++j,++i){
            ans += ss[i];
            if (j<s.size()){
                ans += ss[j];
            }
        }
        return ans;
    }
};
