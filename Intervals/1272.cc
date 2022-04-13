class Solution {
public:
    vector<vector<int>> removeInterval(vector<vector<int>>& intervals, vector<int>& rmv) {
        vector<vector<int>> ans;
        for (auto v:intervals){
            if (v[1]<=rmv[0] || v[0]>=rmv[1]){
                ans.push_back(v);
            }else if (v[0]<rmv[0]){
                ans.push_back({v[0],rmv[0]});
            }
            if (v[0] < rmv[1] && v[1] > rmv[1]) {
                ans.push_back({rmv[1], v[1]});
            }
        }
        return ans;
    }
};
