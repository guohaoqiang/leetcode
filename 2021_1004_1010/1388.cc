class Solution {
public:
    int robrange(vector<int>& slices, int s, int e, int n){
        if (e-s==1){
            return slices.at(s);
        }
        if (e-s==2){
            return max(slices.at(s),slices.at(s+1));
        }
        vector<vector<int>> dp(e-s+1,vector<int>(n+1,0));
        dp.at(1).at(1) = slices.at(s);
        for (int i=2; i<=e-s; ++i){
            for (int j=1; j<=n; ++j){
                dp.at(i).at(j) = max(dp.at(i-1).at(j), dp.at(i-2).at(j-1)+slices.at(s+i-1));
            }
        }
        return dp.back().back();
    }
    
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size()/3;
        // [..., ...)
        int l = robrange(slices, 0, slices.size()-1, n);
        int r = robrange(slices, 1, slices.size(), n);
        
        return max(l,r);
    }
};
