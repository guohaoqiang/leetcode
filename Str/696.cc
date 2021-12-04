//https://leetcode.com/problems/count-binary-substrings/discuss/108625/JavaC%2B%2BPython-Easy-and-Concise-with-Explanation
class Solution {
public:
    int countBinarySubstrings(string s) {
        int prev = 0, cur = 1, ans = 0;
        for (int i=1; i<s.size(); ++i){
            if (s[i]==s[i-1]){
                cur++;
            }else{
                ans += min(prev,cur);
                prev = cur;
                cur = 1;
            }
        }
        return ans + min(prev,cur);
    }
};

