class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int sum = 0;
        for (auto s:stones){
            sum += s;
        }
        int target = sum/2;
        
        vector<int> dp(target+1,0);
        
        for (int i=0; i<stones.size(); ++i){
            for (int j=target; j>=stones.at(i); --j){
                dp.at(j) = max(dp.at(j), dp.at(j-stones.at(i))+stones.at(i));
            }
        }
        return sum-dp.at(target)-dp.at(target);
    }
};
