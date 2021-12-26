class Solution {
public:
    vector<vector<int>> intervalIntersection(vector<vector<int>>& f, vector<vector<int>>& s) {
        int i = 0;
        int j = 0;
        vector<vector<int>> ans;
        while (i<f.size() && j<s.size()){
            int l = max(f[i][0],s[j][0]);
            int r = min(f[i][1],s[j][1]);
            if (l<=r){
                ans.push_back({l,r});
            }
            if (r<f[i][1]){
                j++;
            }else{
                i++;
            }
        }
        return ans;   
    }
};
