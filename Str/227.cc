class Solution {
public:
    int calculate(string s) {
        int sum = 0;
        int num = 0;
        stack<int> st;
        char op = '+';
        
        for (int i=0; i<s.size(); ++i){
            if (s[i]-'0'>=0 && s[i]-'0'<=9){
                num = num*10 + (s[i]-'0');
            }
            
            if ((s[i]-'0'<0 || s[i]-'0'>9) && s[i]!=' ' || i==s.size()-1){
                if (op=='+'){
                    st.push(num);
                }else if (op=='-'){
                    st.push(-num);
                }else if (op=='*'){
                    int tmp = st.top();
                    st.pop();
                    st.push(num*tmp);
                }else if (op=='/'){
                    int tmp = st.top();
                    st.pop();
                    st.push(tmp/num);
                }
                op = s[i];
                num = 0;
            }
        }
        
        while (st.size()){
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
    
};
