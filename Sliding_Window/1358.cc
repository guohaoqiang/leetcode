//https://leetcode.com/problems/number-of-substrings-containing-all-three-characters/discuss/516977/JavaC%2B%2BPython-Easy-and-Concise

class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> tmp(3,0);
        int ans = 0;
        int i = 0;
        for (int j=0; j<s.size(); ++j){
            tmp[s[j]-'a']++;
            while (tmp[0] && tmp[1] && tmp[2]){
                tmp[s[i++]-'a']--;
            }
            ans += i;
        }
        return ans;
    }
};
