class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n,vector<int>(n,0));
        int l = 0;
        int cnt = 1;
        while (l<(n+1)/2){
            for (int i=l; i<n-l; ++i){
                ans[l][i] = cnt++;
            }
            for (int i=l+1; i<n-l; ++i){
                ans[i][n-l-1] = cnt++;
            }
            for (int i=n-l-2; i>=l; --i){
                ans[n-l-1][i] = cnt++;
            }
            for (int i=n-l-2; i>l; --i){
                ans[i][l] = cnt++;
            }
            l++;
        }
        return ans;
    }
};
