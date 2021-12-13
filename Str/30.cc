//https://leetcode.com/problems/substring-with-concatenation-of-all-words/discuss/13658/Easy-Two-Map-Solution-(C++Java)/198418
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int len = words[0].size();
        int n = words.size();
        unordered_map<string,int> counts;
        for (auto w:words){
            counts[w]++;
        }
        vector<int> ans;
        for (int i=0; i<s.size()-n*len+1; ++i){
            unordered_map<string,int> mem;
            int j=0;
            for (; j<n; ++j){
                string str = s.substr(i+j*len,len);
                if (counts.count(str)){
                    mem[str]++;
                    if (mem[str]>counts[str]){
                        break;
                    }
                }else{
                    break;
                }
            }
            if (j==n){
                ans.push_back(i);
            }
        }
        
        return ans;
    }
};
