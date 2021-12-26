class Solution {
public:
    void sortColors(vector<int>& nums) {
        int i = 0;
        int j = nums.size() - 1;
        for (int k=0; k<=j;){
            if (nums[k]==0){
                swap(nums[k++],nums[i++]);
            }else if(nums[k]==2){
                swap(nums[k],nums[j--]);
            }else{
                k++;
            }
        }
    }
};
