class Solution {
public:
    vector<string> ans;
    vector<string> addOperators(string num, int target) {
        
        backtracking(num, 0, "", 0, 0, target);
        return ans;
    }
    void backtracking(string& s, int start, const string& cur, long res, long prev, int t){
        if (start==s.size()){
            if(res==t){
                ans.push_back(cur);
            }
            return;
        }
        
        long num = 0;
        string numstr;
        for (int i=start; i<s.size(); ++i){
            if (i>start && s[start]=='0')   return;
            num = num*10 + (s[i]-'0');
            numstr += s[i];
            if (start==0){
                backtracking(s, i+1, cur+numstr, res+num, num, t);
            }else{
                backtracking(s, i+1, cur+'+'+numstr, res+num, num, t);
                backtracking(s, i+1, cur+'-'+numstr, res-num, -num, t);
                backtracking(s, i+1, cur+'*'+numstr, res-prev+prev*num, prev*num, t);
            }
        }
    }
};
