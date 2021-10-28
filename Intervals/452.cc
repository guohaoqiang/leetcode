class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b){
        if (a[0]==b[0]) return a[1]<b[1];
        return a[0]<b[0];
    }
    int findMinArrowShots(vector<vector<int>>& points) {
        if (points.size()==1)   return 1;
        sort(points.begin(),points.end(),cmp);
        
        int start = INT_MIN;
        int end = INT_MIN;
        int ans = 0;
        for (int i=0; i<points.size(); ++i){
            if (points[i][0]>end){
                ans += 1;
                start = points[i][0];
                end = points[i][1];
            }else {
                start = max(start,points[i][0]);
                end = min(end,points[i][1]);
            }
        }
        
        return ans;
    }
};
