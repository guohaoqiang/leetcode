class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mem;
        for (auto &s:strs){
            string key = keygen2(s);
            mem[key].push_back(s);
        }
        vector<vector<string>> ans;
        for (auto &it:mem){
            ans.push_back(it.second);
        }
        return ans;
    }
    
    string keygen1(string &s){
        vector<int> t(26,0);
        for (auto c:s){
            t[c-'a']++;
        }
        string ans = "";
        for (auto c:t){
            ans += to_string(c) + "$";
        }
        return ans;
    }
    string keygen2(string &s){
        vector<int> t(26,0);
        for (auto c:s){
            t[c-'a']++;
        }
        string ans;
        int i=0; 
        while (i<26){
            if (t[i]==0){
                i++;
            }else {
                ans.push_back(i+'a');
                t[i]--;
            }
        }
        return ans;
    }
};
