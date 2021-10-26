class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans = 0;
        unordered_map<int,int> mp;
        int sum = 0;
        for (int j=0 ;j<nums.size(); j++){
            sum += nums[j];
            if (sum==k){
                ans += 1;
            }
            if (mp.count(sum-k)){
                ans += mp[sum-k];
            }
            mp[sum]++;
        }
        return ans;   
    }
};
