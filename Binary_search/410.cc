class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int n = nums.size();
        int max_ = INT_MIN;
        int sum = 0;
        for (int i=0; i<n; ++i){
            max_ = max(max_, nums[i]);
            sum += nums[i];
        }
        
        int i = max_;
        int j = sum;
        while (i<=j){
            int mid = (i+j)/2;
            int cur = 0;
            int cuts = 0;
            for (int k=0; k<n; ++k){
                cur += nums[k];
                if (cur>mid){
                    cuts++;
                    cur = nums[k];
                    if (cuts>m-1){
                        break;
                    }
                }
            }
            // binary search
            if (cuts>m-1){
                i = mid + 1;
            }else{
                j = mid - 1;
            }
        }
        return i;
    }
};
