//https://leetcode.com/problems/replace-the-substring-for-balanced-string/discuss/408978/JavaC%2B%2BPython-Sliding-Window
class Solution {
public:
    int balancedString(string s) {
        
        int i=0;
        unordered_map<char,int> mem;
        for (auto c:s){
            mem[c]++;
        }
        int len = s.size();
        int ans = INT_MAX;
        for (int j=0; j<len; ++j){
            mem[s[j]]--;
            while (i<len && mem['Q']<=len/4 && mem['E']<=len/4 && mem['W']<=len/4 && mem['R']<=len/4){
                ans = min(ans,j-i+1);
                mem[s[i++]]++;
            }
        }
        return ans;
    }
};
