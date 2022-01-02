class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<long long,int> mp;
        mp[0] = 1;
        int ans = 0;
        long long sum = 0;
        for (int i=0; i<nums.size(); ++i){
            sum += nums[i];
            ans += mp[sum-k];
            mp[sum]++;
        }
        
        return ans;
    }
};
