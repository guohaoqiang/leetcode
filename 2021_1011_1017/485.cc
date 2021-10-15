class Solution {
public:
    bool check(vector<int>& nums, int cut, int sum){
        int psum = 0;
        for (auto num:nums){
            if (num>sum)    return false;
            if (psum+num<=sum){
                psum += num;
            }else {
                cut--;
                if (cut<0){
                    return false;
                }
                psum = num;
            }    
        }
        return true;
    }
    
    int splitArray(vector<int>& nums, int m) {
        auto l = max_element(nums.begin(), nums.end());
        int right = accumulate(nums.begin(), nums.end(), 0);
        int left = *l;
        int mid = (left+right)/2;
        while (left<right){
            if (check(nums, m-1, mid)){
                right = mid;
            }else {
                left = mid + 1;
            }
            mid = (left+right)/2;
        } 
        return left;
    }
};
