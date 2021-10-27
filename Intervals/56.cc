class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
        int start = -1;
        int end = -1;
        sort(intervals.begin(),intervals.end(),cmp);
        vector<vector<int>> ans;
        for (int i=0; i<intervals.size(); ++i){
            if (intervals[i][0]>end){
                if (i!=0) ans.push_back({start,end});
                start = intervals[i][0];
            }
            end = max(end,intervals[i][1]);
        }
        ans.push_back({start,end});
        return ans;
    }
}
