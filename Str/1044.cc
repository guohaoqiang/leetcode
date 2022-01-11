class Solution {
public:
    int mod = 1e7+7;
    vector<int> power;
        
    string longestDupSubstring(string s) {
        int n = s.size();
        power.resize(n);
        power[0] = 1;
        for (int i=1; i<n; ++i){
            power[i] = power[i-1]*26%mod;
        }
        int i=1;
        int j=n;
        string ans;
        while (i<=j){
            int mid = (i+j)/2;
            string dup = helper(s,mid);
            if (dup.size()>ans.size()){
                i = mid+1;
                ans = dup;
            }else{
                j = mid-1;
            }
        }
        return ans;
    }
    string helper(string& s, int len){
        unordered_map<int,vector<int>> mp;
        
        int key = 0;
        for (int i=0; i<len; ++i){
            key = (key*26 +(s[i]-'a'))%mod;
        }
        mp[key] = {0};
        for (int i=len; i<s.size(); ++i){
            key = ((key-power[len-1]*(s[i-len]-'a'))%mod + mod)%mod;
            key = (key*26 + (s[i]-'a'))%mod;
            
            if (!mp.count(key)){
                mp[key] = {i-len+1};
                continue;
            }
            string gold = s.substr(i-len+1,len);
            for (int j=0; j<mp[key].size(); ++j){
                if (s.substr(mp[key][j],len)==gold){
                    return gold;
                }
            }
            mp[key].push_back(i-len+1);
            
        }
        return "";
    }
};

