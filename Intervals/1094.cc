class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> t;
        
        for (auto &it:trips){
            t[it[1]] += it[0];
            t[it[2]] -= it[0];
        }
        int curr = 0;
        for (auto &it:t){
            curr += it.second;
            if (curr>capacity){
                return false;
            }
        }
        return true;
    }
};
