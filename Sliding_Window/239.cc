// https://leetcode.com/problems/sliding-window-maximum/discuss/65898/Clean-C%2B%2B-O(n)-solution-using-a-deque

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> ans;
        int i = 0;
        for (int j=0; j<nums.size(); ++j){
            
            if (j>=k && q.size() && q.front()==nums[j-k]){
                q.pop_front();
            }
            // maintain a descending queue
            while (q.size() && nums[j]>q.back()){
                q.pop_back();
            }
            q.push_back(nums[j]);
            if (j>=k-1 && q.size()){
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};
