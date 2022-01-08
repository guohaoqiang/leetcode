class Solution {
public:
    int calculate(string s) {
        int op = '+';
        int num = 0;
        stack<int> st;
        int ans = 0;
        for (int i=0; i<s.size(); ++i){
            int b = 0;
            if (s[i]>='0' && s[i]<='9'){
                num = num*10 + (s[i]-'0');
            }else if (s[i]=='('){
                int j = i+1;
                b++;
                while (b>0){
                    if (s[j]=='('){
                        b++;
                    }else if (s[j]==')'){
                        b--;
                    }
                    j++;
                }
                num = calculate(s.substr(i+1,j-i-1));
                i = j-1;
            }
            if (s[i]=='+' || s[i]=='-' || s[i]=='*' || s[i]=='/' || i==s.size()-1){
                if (op=='+'){
                    st.push(num);
                }else if (op=='-'){
                    st.push(-num);
                }else if (op=='*'){
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp*num);
                }else if (op=='/'){
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp/num);
                }
                op = s[i];
                num = 0;
            } 
        }
                          
        while (!st.empty()){
            ans += st.top();
            st.pop();
        }            
        return ans;
    }
};
