//https://leetcode.com/problems/count-unique-characters-of-all-substrings-of-a-given-string/discuss/128952/C%2B%2BJavaPython-One-pass-O(N)

class Solution {
public:
    int uniqueLetterString(string s) {
        vector<vector<int>> pos(26,vector<int>(2,-1));
        int ans = 0;
        int n = s.size();
        
        for (int i=0; i<n; ++i){
            int p = s[i] - 'A';
            ans += (i-pos[p][1])*(pos[p][1]-pos[p][0]);
            pos[p][0] = pos[p][1];
            pos[p][1] = i;
        }
        for (int i=0; i<26; ++i){
            ans += (n-pos[i][1])*(pos[i][1]-pos[i][0]);
        }
        
        return ans;
    }
};
