class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int kmod = 1e9+7;
        
        vector<vector<int>> dp(minProfit+1,vector<int>(n+1,0));
        dp.at(0).at(0) = 1;
        
        for (int i=0; i<group.size(); ++i){
            int p = profit.at(i);
            int g = group.at(i);
            for (int j=minProfit; j>=0; --j){
                int ip = min(minProfit,j+p);
                for (int k=n-g; k>=0; --k){
                    dp.at(ip).at(k+g) = (dp.at(ip).at(k+g) + dp.at(j).at(k))%kmod;
                }
            }
        }
        /*
        int ans = 0;
        for (int c=0; c<=n; ++c){
            ans = (ans+dp.at(minProfit).at(c))%kmod;
        }
        
        return ans;
        */
        return accumulate(dp.at(minProfit).begin(),dp.at(minProfit).end(),0ll)%kmod;
    }
};
