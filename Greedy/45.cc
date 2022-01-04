class Solution {
public:
    int jump(vector<int>& nums) {
        int cur_cover = 0;
        int next_cover = 0;
        int ans = 0;
        int i = 0;
        
        while (i<nums.size()-1){
            
            next_cover = max(i+nums[i], next_cover);

            if (cur_cover == i){
                ans++;
                cur_cover = next_cover;
            }
            i++;
        }
        
        return ans;
    }
};
