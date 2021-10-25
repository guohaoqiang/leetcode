class Solution {
public:
    vector<vector<int>> twoSum(vector<int>& nums, int target, int base){
        vector<vector<int>> ans;
        int i=base;
        int j=nums.size()-1;
        while (i<j){
            if (nums[i]+nums[j]>target){
                j--;
            }else if (nums[i]+nums[j]<target){
                i++;
            }else {
                ans.push_back({nums[i],nums[j]});
                while (i<j && nums[i]==ans.back()[0])   i++;
                while (i<j && nums[j]==ans.back()[1])   j--;
            }
        }
        return ans;
    }
    vector<vector<int>> ksum(vector<int>& nums, int target, int base, int k){
        vector<vector<int>> ans;
        int avg = target/k;
        if (base==nums.size() || avg<nums[base] || avg>nums.back()){
            return ans;
        }
        if (k==2){
            return twoSum(nums, target, base);
        }
        for (int i=base; i<nums.size(); ++i){
            if (i==base || nums[i]!=nums[i-1]){
                for (auto sub:ksum(nums,target-nums[i],i+1,k-1)){
                    ans.push_back({nums[i]});
                    ans.back().insert(ans.back().end(),sub.begin(),sub.end());
                }
            }
        }
        return ans;
    }
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(),nums.end());
        return ksum(nums,target,0,4);
    }
};
