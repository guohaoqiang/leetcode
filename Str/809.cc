//https://leetcode.com/problems/expressive-words/discuss/122660/C%2B%2BJavaPython-2-Pointers-and-4-pointers
class Solution {
public:
    bool check(string& s, string& w){
        int m = s.size(), n = w.size();
        int j = 0;
        for (int i=0; i<m; ++i){
            if (j<n && s[i]==w[j])  j++;
            else if(i>0 && i<m-1 && s[i-1]==s[i] && s[i]==s[i+1])   ;
            else if(i>1 && s[i]==s[i-1] && s[i]==s[i-2])    ;
            else return false;
        }
        return j==n;
    }
    int expressiveWords(string s, vector<string>& words) {
        int ans = 0;
        for (auto w:words){
            if (check(s,w)) ans++;
        }
        return ans;
    }
};
