class Solution {
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        unordered_map<string,vector<string>> mem;
        
        for (auto s:strings){
            string key = keygen(s);
            mem[key].push_back(s);
        }
        
        vector<vector<string>> ans;
        for (auto &it:mem){
            ans.push_back(it.second);
        }
        return ans;
    }
    string keygen(const string& s){
        vector<int> dif;
        for (int i=1; i<s.size(); ++i){
            dif.push_back((s[i]-s[i-1]+26)%26);
        }
        
        string key = "";
        for (auto d:dif){
            key += to_string(d)+"$";
        }
        return key;
    }
};
