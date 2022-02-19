class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        vector<int> ans(nums.size(),0);
        vector<int> ind(nums.size(),0);
        iota(ind.begin(),ind.end(),0);
        
        helper(nums, 0, nums.size(), ind, ans);
        return ans;
    }
    void helper(vector<int>& nums, int start, int end, vector<int>& ind, vector<int>& ans){
        int count = end - start;
        if (count>1){
            int mid = (end+start)/2;
            
            helper(nums, start, mid, ind, ans);
            helper(nums, mid, end, ind, ans);
            
            vector<int> tmp;
            int i = start;
            int j = mid;
            int semicount = 0;
            while (i<mid || j<end){
                if (j==end || (i<mid && nums[ind[i]]<=nums[ind[j]])){
                    tmp.push_back(ind[i]);
                    ans[ind[i]] += semicount;
                    i++;
                }else{
                    semicount++;
                    tmp.push_back(ind[j]);
                    j++;
                }
            }
            move(tmp.begin(), tmp.end(), ind.begin()+start);
        }
    }
};
