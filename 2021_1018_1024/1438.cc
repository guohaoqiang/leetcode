class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int len = nums.size();
        if (len==1){
            return 1;
        }
        int slowPointer = 0;
        int fastPointer = 0;
        int ans = INT_MIN;
        multiset<int> q;
        while (fastPointer<len){
            q.insert(nums[fastPointer]);
            
            int dif = *q.rbegin()-*q.begin();
            if (dif>limit){
                q.erase(q.find(nums[slowPointer++]));
            }
            
            fastPointer++;
        }
        return fastPointer-slowPointer;
    }
};
