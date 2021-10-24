// https://leetcode.com/problems/longest-repeating-character-replacement/discuss/278271/JavaC%2B%2BPython-Sliding-Window-just-O(n)

class Solution {
public:
    int characterReplacement(string s, int k) {
        unordered_map<char,int> count;
        int ans = 0;
        int maxc = 0;
        for (int i=0; i<s.size(); ++i){
            maxc = max(++count[s[i]],maxc);
            if (ans-maxc<k){
                ans++;
            }else {
                count[s[i-ans]]--;
            }
        }
        return ans;
    }
};
