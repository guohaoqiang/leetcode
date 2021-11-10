class Solution {
public:
    vector<vector<int>> ans;
    vector<int> sub;
    void dfs(vector<int>& nums, vector<bool>& flag){
        if (sub.size()==nums.size()){
            ans.push_back(sub);
            return ;
        }
        
        for (int i=0; i<nums.size(); ++i){
            if (!flag[i]){
                sub.push_back(nums[i]);
                flag[i] = true;
                dfs(nums,flag);
                flag[i] = false;
                sub.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> flags(nums.size(),false);
        
        dfs(nums,flags);
        return ans;
    }
};
