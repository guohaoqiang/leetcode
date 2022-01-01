class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void helper(vector<int>& nums, int start, int len){
        if (sub.size()==len){
            ans.push_back(sub);
            return ;
        }
        
        for (int i=start; i<nums.size(); ++i){
            if (i>start && nums[i-1]==nums[i]){
                continue;
            }
            sub.push_back(nums[i]);
            helper(nums,i+1,len);
            sub.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        ans.push_back(sub);
        for (int l=1; l<=nums.size(); ++l){
            helper(nums,0,l);
        }
        return ans;
    }
};
