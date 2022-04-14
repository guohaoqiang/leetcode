class Solution {
public:
    string countOfAtoms(string formula) {
        reverse(formula.begin(), formula.end());
        
        map<string,int> m;
        check(formula, m);
        
        string ans = "";
        for (auto& it:m){
            ans += it.first;
            if (it.second>1)
                ans += to_string(it.second);
        }
        return ans;
    }
    void check(string& s, map<string,int>& m){
        stack<int> st;
        st.push(1);
        string atom = "";
        int num = 1;
        for (size_t i=0; i<s.size(); ++i){
            char ch = s[i];
            if (isdigit(ch)){
                num = 0;
                int exp = 1;
                do{
                    num += (ch-'0')*exp;
                    exp *= 10;
                    ch = s[++i];
                }while(isdigit(ch));
                i--;
            }else if (ch==')'){
                st.push(st.top()*num);
                num = 1;
            }else if (ch>='A' && ch<='Z'){
                atom = ch + atom;
                //reverse(atom.begin(), atom.end());
                m[atom] += st.top()*num;
                atom.clear();
                num = 1;
            }else if (ch>='a' && ch<='z'){
                atom = ch + atom;
            }else{
                // ch == '('
                st.pop();
            }
        }
    }
    
};
