class Solution {
public:
    bool backspaceCompare(string s, string t) {
        int i = s.size()-1;
        int j = t.size()-1;
        int skip_s = 0;
        int skip_t = 0;
        while (i>=0 || j>=0){
            while (i>=0){
                if (s[i]=='#'){
                    i--; skip_s++;
                }else if (skip_s){
                    skip_s--; i--;
                }else{
                    break;
                }
            }
            while (j>=0){
                if (t[j]=='#'){
                    j--; skip_t++;
                }else if (skip_t){
                    skip_t--; j--;
                }else{
                    break;
                }
            }
            if (i>=0 && j>=0 && s[i]!=t[j]) return false;
            if ((i>=0)!=(j>=0)) return false;
            i--; j--;
        }
        return true;
    }
};
