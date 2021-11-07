class Solution {
public:
    static bool cmp(vector<int>& a,vector<int>& b){
        return a[1]<b[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),cmp);
        int ans = 1;
        int end = pairs[0][1];
        for (auto job:pairs){
            if (job[0]>end){
                ans++;
                end = job[1];
            }
        }
        return ans;
    }
};
