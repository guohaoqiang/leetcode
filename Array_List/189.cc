//https://leetcode.com/problems/rotate-array/discuss/54277/Summary-of-C%2B%2B-solutions

class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        
        int i = 0;
        int c = 0;
        int idx = 0;
        while (c<nums.size()){
            int temp = nums[i];
            do
            {
                swap(nums[(i+k)%nums.size()],temp);
                i = (i+k)%nums.size();
                c++;
            }while (i!=idx);
            idx++;
            i = idx;
        }
        return ;
    }
};
