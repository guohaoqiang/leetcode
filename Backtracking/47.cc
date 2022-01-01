class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void helper(vector<int>& nums, vector<bool>& flag){
        if (sub.size()==nums.size()){
            ans.push_back(sub);
            return ;
        }
        for (int i=0; i<nums.size(); ++i){
            if (i>0){
                if (nums[i]==nums[i-1] && !flag[i-1]){
                    continue;
                }
            }
            if (flag[i])   continue;
            sub.push_back(nums[i]);
            flag[i] = true;
            helper(nums,flag);
            sub.pop_back();
            flag[i] = false;
        }
        
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        sort(nums.begin(),nums.end());
        
        helper(nums,flag);
        
        return ans;
    }
};
