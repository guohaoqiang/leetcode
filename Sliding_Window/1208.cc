//https://leetcode.com/problems/get-equal-substrings-within-budget/discuss/392837/JavaC%2B%2BPython-Sliding-Window

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int len = s.size();
        int i = 0;
        for (int j=0; j<len; ++j){
            if((maxCost -= abs(s[j]-t[j]))<0){
                maxCost += abs(s[i]-t[i]);
                ++i;
            }
        }
        return len-i;
    }
};
