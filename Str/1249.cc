class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int l = 0, b = 0;
        stack<int> st;
        string tmp = "";
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='('){
                l++; b++;
            }else if (s[i]==')'){
                if (b==0){
                    st.push(i);
                    continue;
                }
                b--;
            }
            tmp += s[i];
        }
        // tmp has the same number of '(' and ')'
        //
        if ( b==0 && st.empty() )   return tmp;
        // tmp has more '(' than ')'
        int k = l - b; // #'(' needs to be kept
        string ans = "";
        for (auto c:tmp){
            if (c=='('){
                if (k<=0){
                    continue;
                }
                k--;
            }
            ans += c;
        }
        return ans;
    }
};
