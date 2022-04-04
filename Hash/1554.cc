class Solution {
public:
    int mod = 1e9+7;
    bool differByOne(vector<string>& dict) {
        size_t n = dict.size();
        size_t l = dict[0].size();
        vector<int> h(n,0);
        for (size_t i=0; i<n; ++i){
            for (size_t j=0; j<l; ++j){
                h[i] = (h[i]*26l + (dict[i][j]-'a'))%mod;
            }
        }
        int mul = 1;
        for (int j=l-1; j>=0; --j){
            unordered_map<int,vector<size_t>> mp;
            for (size_t i=0; i<n; ++i){
                int key = (h[i]+mod-(long)mul*(dict[i][j]-'a')%mod)%mod;
                auto it = mp.find(key);
                if (it != mp.end()){
                    // check the collision issue
                    // note here the i-th string hasnot been insert into mp
                    
                    for (auto k:(*it).second){
                        if (equal(dict[i].begin(), dict[i].begin()+j, dict[k].begin()) && 
                            equal(dict[i].begin()+j+1, dict[i].end(), dict[k].begin()+j+1)){
                            return true;
                        }
                    }
                    
                }
                mp[key].push_back(i);
            }
            mul = 26l * mul % mod;
        }
        return false;
    }
};
