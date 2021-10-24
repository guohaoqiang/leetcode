//https://leetcode.com/problems/subarrays-with-k-different-integers/discuss/523136/JavaC%2B%2BPython-Sliding-Window

class Solution {
public:
    int search(vector<int>& nums, int k){
        int len = nums.size();
        int ans = 0;
        unordered_map<int,int> record;
        
        int i = 0;
        for (int j=0; j<len; ++j){
            if (!record[nums[j]]++)  k--;
            while (k<0){
                if (!--record[nums[i++]])  k++;
            }
            ans += j-i+1;
        }
        return ans;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return search(nums,k)-search(nums,k-1);
    }
};
