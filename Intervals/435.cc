class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        return a[1]<b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& t) {
        sort(t.begin(),t.end(),cmp);
        
        int r = t[0][1];
        int ans = 1;
        for (int i=1; i<t.size(); ++i){
            if (t[i][0]>=r){
                r = t[i][1];
                ans++;
            }
        }
        return t.size()-ans;
    }
};
