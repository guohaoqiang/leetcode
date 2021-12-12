//dp solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.size();
        vector<int> dp(n+1,0);
        int ans = 0;
        for (int i=1; i<n; ++i){
            if (s[i]==')'){
                if (s[i-1]=='('){
                    dp[i] = (i>=2?dp[i-2]:0) + 2;
                }else if(i>dp[i-1] && s[i-dp[i-1]-1]=='('){
                    dp[i] = dp[i-1] + 2 + ((i>dp[i-1]+1) ? dp[i-dp[i-1]-2] : 0);
                }   
            }
            ans = max(dp[i],ans);
        }
        return ans;
    }
};
//tricky solution
class Solution {
public:
    int longestValidParentheses(string s) {
        int mx = 0;
        int l = 0, r = 0;
        
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='('){
                l++;
            }else{
                r++;
            }
            if(l==r)    mx = max(mx,r+l);
            else if(r>l)    {l=0; r=0;}
        }
        l=0; r=0;
        for (int i=s.size()-1; i>=0; --i){
            if (s[i]=='('){
                l++;
            }else{
                r++;
            }
            if(l==r)    mx = max(mx,r+l);
            else if(l>r)    {l=0; r=0;}
        }
        
        return mx;
    }
};
//stack solution
class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        st.push(-1);
        int ans = 0;
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='('){
                st.push(i);
            }else{
                st.pop();
                if (st.empty()){
                    st.push(i);
                }else{
                    ans = max(ans,i-st.top());
                }
            }
        }
        return ans;
    }
};
