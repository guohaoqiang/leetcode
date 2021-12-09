//https://leetcode.com/problems/flip-string-to-monotone-increasing/discuss/189751/C%2B%2B-one-pass-DP-solution-0ms-O(n)-or-O(1)-one-line-with-explaination.
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        
        int n = s.size();
        int flips = 0;
        int ones = 0;
        
    
        if (s[0]=='1') ones = 1;
        
        for (int i=1; i<s.size(); ++i){
            if (s[i]=='1'){
                ones++;
            }else{
                flips = min(ones,flips+1);
            }
        }
        
        return flips;
    }
};
