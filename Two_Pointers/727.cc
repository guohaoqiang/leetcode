//https://leetcode.com/problems/minimum-window-subsequence/discuss/385670/No-need-to-use-map-or-dp-!!-It-is-just-simple-2-pointer-(C%2B%2B-beat-92-O(1)-space)
class Solution {
public:
    string minWindow(string s1, string s2) {
        
        int len = 0;
        int j = 0;
        int start = -1;
        for (int i=0; i<s1.size(); ++i){
            if (s1[i]==s2[j]){
                j++;
            }
            if (j==s2.size()){
                int k = i;
                while (j>0){
                    if (s2[j-1]==s1[k]){
                        j--;
                    }
                    k--;
                }
                
                if (len==0 || i-k<len){
                    len = i-k;
                    start = k+1;
                }
                
                i = k+1;
            }
        }
        
        return start>-1? s1.substr(start,len) : "";
    }
};
