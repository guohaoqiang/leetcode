class Solution {
public:
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        
        int lo = 0;
        int hi = n-1;
        int mid = 0;
        while (lo<=hi){
            mid = (lo+hi)/2;
            if (nums[mid]==target) return mid;
            if (nums[mid]>=nums[lo]){
                if (nums[mid]>target && target>=nums[lo])  hi = mid-1; 
                else lo = mid+1;
            }else {
                if (nums[mid]<target && target<=nums[hi])   lo = mid+1;
                else hi = mid-1;
            }
        }
        return -1;
    }
};
