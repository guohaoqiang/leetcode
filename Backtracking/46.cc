class Solution {
public:
    vector<vector<int>> ans;
    vector<int> res;
    void backtracking(vector<int>& nums, vector<bool>& flag){
        if (res.size()==nums.size()){
            ans.push_back(res);
        }
        
        for (int i=0; i<nums.size(); ++i){
            if (flag[i]){
                continue;
            }
            flag[i] = true;
            res.push_back(nums[i]);
            backtracking(nums,flag);
            res.pop_back();
            flag[i] = false;
        }
        
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flag(nums.size(),false);
        backtracking(nums,flag);
        
        return ans;
    }
};
