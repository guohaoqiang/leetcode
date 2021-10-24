// https://leetcode.com/problems/shortest-subarray-with-sum-at-least-k/discuss/143726/C%2B%2BJavaPython-O(N)-Using-Deque

class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> q;
        int ans = nums.size()+1;
        for (int i=0; i<nums.size(); ++i){
            //prefix sum
            if (i>0){
                nums[i] += nums[i-1];
            }
            if (nums[i]>=k){
                ans = min(ans,i+1);
            }
            // shorten the valid subarray
            while (q.size() && nums[i]-nums[q.front()]>=k){
                ans = min(ans, i-q.front());
                q.pop_front();
            }
            // maintain an ascending queue
            while (q.size() && nums[q.back()]>nums[i]){
                q.pop_back();
            }
            q.push_back(i);
        }
        
        return ans<=nums.size()? ans : -1;
    }
};
