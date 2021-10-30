class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<int> c_pos;
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='|'){
                c_pos.push_back(i);
            }
        }
        
        for (auto q:queries){
            int i = lower_bound(c_pos.begin(),c_pos.end(),q[0])-c_pos.begin();
            int j = upper_bound(c_pos.begin(),c_pos.end(),q[1])-c_pos.begin()-1;
            // (plates+ candles) - candles
            int cts = (i<j)? (c_pos[j]-c_pos[i])-(j-i): 0;
            ans.push_back(cts);
        }
        return ans;
    }
};
