// O(1) space complexity
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int ans = INT_MIN;
        int cts = 0;
        for (auto num:nums){
            if (cts==0){
                ans = num;
            }
            cts += (ans==num)? 1 : -1;
        }
        
        return ans;
    }
};
