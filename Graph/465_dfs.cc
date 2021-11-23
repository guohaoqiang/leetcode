class Solution {
public: 
    vector<int> vec;
    int minTransfers(vector<vector<int>>& transactions) {
        unordered_map<int,int> mem;
        for (auto trs:transactions){
            mem[trs[0]] -= trs[2];
            mem[trs[1]] += trs[2];
        }
        
        for (auto m:mem){
            if (m.second)  vec.push_back(m.second);
        }
        
        return dfs(0);
    }
    
    int dfs(int s){
        
        while (s<vec.size() && !vec[s]) ++s;
        
        int prev = 0;
        int ans = INT_MAX;
        for (int i=s+1; i<vec.size(); ++i){
            if (vec[i]!=prev && vec[i]*vec[s]<0){
                vec[i] += vec[s];
                ans = min(ans,1+dfs(s+1));
                vec[i] -= vec[s];
                prev = vec[i];
            }
        }
        return ans==INT_MAX? 0 : ans;
    }
    
};
