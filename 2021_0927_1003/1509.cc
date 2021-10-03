class Solution {
public:
    int minDifference(vector<int>& nums) {
        int n = nums.size();
        if (n<=4){
            return 0;
        }
        
        //sort(nums.begin(),nums.end());
        partial_sort(nums.begin(), nums.begin()+4, nums.end());
        nth_element(nums.begin()+4, nums.end()-4,nums.end());
        sort(nums.end()-4, nums.end());
        
        return min({nums.at(n-1)-nums.at(3), nums.at(n-4)-nums.at(0), nums.at(n-2)-nums.at(2), nums.at(n-3)-nums.at(1)});
        
        
    }
};
