// https://leetcode.com/problems/maximum-number-of-visible-points/discuss/877735/C%2B%2B-Clean-with-Explanation

class Solution {
public:
   
    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& loc) {
        vector<double> vals;
        int common = 0;
        for (auto p:points){
            if (p[0]==loc[0] && p[1]==loc[1]) {
                common++;
                continue;
            }
            double ang = atan2(p[1]-loc[0],p[0]-loc[1])*180/M_PI;
            if (ang<0)  ang += 360;
            vals.push_back(ang);
        }
        sort(vals.begin(), vals.end());
        vector<double> arr(vals);
        
        for (auto v:vals){
            arr.push_back(v+360);
        }
        
        int ans = 0;
        int j = 0;
        for (int i=0; i<arr.size(); ++i){
            while (j<arr.size() && arr[j]-arr[i]<angle+0.0001){
                j++;
            }
            ans = max(ans,j-i);
        }
        
        return ans + common;
    }
};
