class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> m1(26,0);
        for (auto c:p){
            m1[c-'a']++;
        }
        vector<int> ans;
        vector<int> m2(26,0);
        int i=0;
        for (int j=0; j<s.size(); ++j){
            m2[s[j]-'a']++;
            
            if (j-i==p.size()-1){
                int k = 0;
                while (k<26){
                    if (m1[k]!=m2[k]){
                        break;
                    }
                    k++;
                }
                if (k==26) ans.push_back(i);
                m2[s[i++]-'a']--;
            }
        }
        return ans;
    }
};
