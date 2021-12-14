//https://leetcode.com/problems/permutation-in-string/discuss/638531/Java-or-C%2B%2B-or-Python3-or-Detailed-explanation-or-O(N)-time
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if (s1.size()>s2.size())    return false;
        vector<int> mp(26,0);
        
        for (auto c:s1) mp[c-'a']++;
        int i=0, j=0;
        int counts = s1.size();
        while (j<s2.size()){
            if (mp[s2[j]-'a']>0){
                counts--;
            }
            mp[s2[j++]-'a']--;
            if (counts==0)  return true;
            if (j-i==s1.size()){
                if (mp[s2[i]-'a']>=0)
                    counts++;
                mp[s2[i++]-'a']++;
            }
        }
        return false;
    }
};
