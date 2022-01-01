class Solution {
public:
    vector<vector<int>> ans;
    vector<int> cur;
    void helper(vector<int>& nums, int k, int len){
        if (cur.size()==len){
            ans.push_back(cur);
            return ;
        }
        if (k==nums.size()) return;
        for (int i=k; i<nums.size(); ++i){
            cur.push_back(nums[i]);
            helper(nums,i+1,len);
            cur.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        ans.push_back(cur);
        for (int l=1; l<=nums.size(); ++l){
            helper(nums,0,l);
        }
        return ans;
    }
};
