//https://leetcode.com/problems/constrained-subsequence-sum/discuss/597751/JavaC++Python-O(N)-Decreasing-Deque

class Solution {
public:
    int constrainedSubsetSum(vector<int>& nums, int k) {
        deque<int> q;
        int ans = nums[0];
        int len = nums.size();
    
        for (int j=0; j<len; ++j){
            nums[j] += q.size()? q.front() : 0;
            ans = max(ans,nums[j]);
            
            while (q.size() && q.back()<nums[j]){
                q.pop_back();
            }
            
            if (nums[j]>0){
                q.push_back(nums[j]);
            }
            if (j>=k && q.size() && q.front()==nums[j-k]){
                q.pop_front();
            }
            
        }
        
        return ans;
    }
};
