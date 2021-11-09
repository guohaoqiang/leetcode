class Solution {
public:
    vector<string> dict{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    string sub;
    vector<string> ans;
    vector<string> letterCombinations(string digits) {
        if (digits.size()==0)    return ans;
        
        build(digits,0);
        return ans;
    }
    void build(string s, int start){
        if (sub.size()==s.size()){
            ans.push_back(sub);
            return ;
        }
        
        for (int i=0; i<dict[s[start]-'2'].size(); ++i){
            sub.push_back(dict[s[start]-'2'][i]);
            build(s,start+1);
            sub.pop_back();
        }
    }
};
