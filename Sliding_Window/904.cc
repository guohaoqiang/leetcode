// https://leetcode.com/problems/fruit-into-baskets/discuss/170745/Problem:-Longest-Subarray-With-2-Elements/742259

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int a = 0, b = 0, cur = 0, cur_b = 0;
        
        int ans = 0;
        for (auto c:fruits){
            // cur is the current length
            cur = (c==a || c==b)? cur+1 : cur_b+1;
            // cur_b is the length of the consecutive last element
            cur_b = (c==b)? cur_b+1 : 1;
            if (c!=b)   a = b, b = c; 
            ans = max(ans, cur);
        }
        return ans;
    }
};
