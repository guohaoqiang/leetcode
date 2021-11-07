class Solution {
public:
    int calculate(string s) {
        int ans = 0;
        int num = 0;
        int sign = 1;
        stack<int> result;
        stack<int> signs;
        for (auto c:s){
            if(c>='0' && c<='9'){
                num = num*10 + (c-'0');
            }else if (c=='+'){
                ans += sign*num;
                sign = 1;
                num = 0;
            }else if (c=='-'){
                ans += sign*num;
                sign = -1;
                num = 0;
            }else if (c=='('){
                signs.push(sign);
                result.push(ans);
                num = 0;
                ans = 0;
                sign = 1;
            }else if (c==')') {
                ans += sign*num; 
                ans = ans*signs.top() + result.top();
                signs.pop();
                result.pop();
                num = 0;
                sign = 1;
            }
        }
        ans += sign*num;
        
        return ans;
    }
};
