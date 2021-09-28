class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        vector<vector<int>> dp(m+1,vector<int>(n+1,0));
        
        for (int i=0; i<strs.size(); ++i){
            int zero = 0, one = 0;
            for (auto e:strs.at(i)){
                if (e=='0') zero++;
                else one++;
            }
            
            for (int j=m; j>=zero; --j){
                for (int k=n; k>=one; --k){
                    dp.at(j).at(k) = max(dp.at(j).at(k), dp.at(j-zero).at(k-one)+1);
                }
            }
        }
        return dp.back().back();
    }
};
