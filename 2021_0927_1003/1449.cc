class Solution {
public:
    string largestNumber(vector<int>& cost, int target) {
        vector<int> dp(target+1, INT_MIN);
        dp.at(0) = 0;
        // 1st step: caculate the largest number of digits to meet the target requirement
        for (int i=1; i<=target; ++i){
            for (int j=0; j<cost.size(); ++j){
                if (i>=cost.at(j)){
                    dp.at(i) = max(dp.at(i-cost.at(j))+1,dp.at(i));
                }
            }
        }
        if (dp.at(target)<=0){
            return "0";
        }
        
        string ans = "";
        // reverse traversal enables larger digits to be placed on the left
        for (int i=cost.size()-1; i>=0; --i){
            while (target>=cost.at(i) && dp.at(target)==dp.at(target-cost.at(i))+1){
                ans.push_back(i+'1');
                target -= cost.at(i);
            }
        }
        return ans;
    }
};
