//https://leetcode.com/problems/3sum/discuss/7402/Share-my-AC-C%2B%2B-solution-around-50ms-O(N*N)-with-explanation-and-comments

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for (int p=0; p<nums.size(); ++p){
            int i = p+1;
            int j = nums.size()-1;
            if (p==0 || nums[p]!=nums[p-1]){
                while (i<j){
                    if (nums[i]+nums[j]>-nums[p]){
                        j--;
                    }else if (nums[i]+nums[j]<-nums[p]){
                        i++;
                    }else{
                        ans.push_back({nums[p],nums[i],nums[j]});
                        //remove duplicates of the second entry
                        while (i<j && nums[i]==ans.back()[1]){
                            i++;
                        }
                        //remove duplicates of the third entry
                        while (i<j && nums[j]==ans.back()[2]){
                            j--;
                        }
                    }
                }
            }
        }
        return ans;
    }
    
};
