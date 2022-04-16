// https://leetcode.com/problems/string-transforms-into-another-string/discuss/355382/JavaC%2B%2BPython-Need-One-Unused-Character
class Solution {
public:
    bool canConvert(string str1, string str2) {
        if (str1==str2) return true;
        unordered_map<char,char> m;
        if (str1.size()!=str2.size())   return false;
        for (size_t i=0; i<str1.size(); ++i){
            if (m.count(str1[i]) && m[str1[i]]!=str2[i]){
                return false;
            }
            m[str1[i]] = str2[i];
        }
        
        return unordered_set<char>(str2.begin(),str2.end()).size()<26;
    }
};
