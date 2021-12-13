class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mn = prices[0];
        
        int ans = 0;
        for (auto p:prices){
            if (p<mn){
                mn = p;
            }
            ans = max(ans, p-mn); 
        }
        
        return ans;
    }
};
