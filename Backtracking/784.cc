class Solution {
public:
    vector<string> ans;
    void backtracking(string& s, vector<int>& pos, int start){
        //ans.push_back(s);
        for (int i=start; i<pos.size(); ++i){
            char ori = s[pos[i]];
            if (s[pos[i]]>='a' && s[pos[i]]<='z'){
                s[pos[i]] = (s[pos[i]]-'a'+'A');
            }else{
                s[pos[i]] = (s[pos[i]]-'A'+'a');
            }
            ans.push_back(s);
            backtracking(s, pos, i+1);
            s[pos[i]] = ori;
        }
    }
    vector<string> letterCasePermutation(string s) {
        vector<int> pos;
        for (int i=0; i<s.size(); ++i){
            if (!isdigit(s[i])){
                pos.push_back(i);
            }
        }
        ans.push_back(s);
        backtracking(s, pos, 0);
        return ans;
    }
};
