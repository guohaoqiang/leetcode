class Solution {
public:
    
    int tallestBillboard(vector<int>& rods) {
        int sum = accumulate(rods.begin(), rods.end(), 0);
        vector<vector<int>> dp(21,vector<int>(sum+1,0));
        for (int k=1; k<sum+1; ++k){
            dp.at(0).at(k) = INT_MIN;
        }
        
        for (int i=1; i<=rods.size(); ++i){
            for (int j=0; j<=sum; ++j){
                dp.at(i).at(j) = dp.at(i-1).at(j);
                // add the i-th rod to the large bag. 
                if (rods.at(i-1)<=j){
                    dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(j-rods.at(i-1))+rods.at(i-1));
                }
                
                // add the i-th rod to the small bag. w/o switch
                if (rods.at(i-1)+j<=sum){
                    dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(rods.at(i-1)+j));
                }
                // add the i-th rod to the small bag. w/ switch
                if (rods.at(i-1)>j){
                    dp.at(i).at(j) = max(dp.at(i).at(j), dp.at(i-1).at(rods.at(i-1)-j)+j);
                }
            }
        }
        
        return dp.at(rods.size()).at(0);
    }
};
