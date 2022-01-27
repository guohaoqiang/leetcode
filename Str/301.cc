// BFS
class Solution {
public:
    bool check(string& s){
        int cnt=0;
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='('){
                cnt++;
            }else if (s[i]==')'){
                cnt--;
                if (cnt<0)  return false;
            }
        }
        return cnt==0;
    }
    vector<string> removeInvalidParentheses(string s) {
        unordered_set<string> st;
        queue<string> q;
        q.push(s);
        unordered_set<string> v;
        v.insert(s);
        while (!q.empty()){
            int sz = q.size();
            for (int i=0; i<sz; ++i){
                auto top = q.front();
                q.pop();
                if (check(top)) st.insert(top);
                
                if (st.empty()){
                    for (int k=0; k<top.size(); ++k){
                        if (top[k]=='(' || top[k]==')'){
                            string tmp = top.substr(0,k)+top.substr(k+1);
                            if (!v.count(tmp)){
                                v.insert(tmp);
                                q.push(tmp);
                            }
                        }
                    }
                }
            }
            
            if (!st.empty())    return vector<string>(st.begin(),st.end());
        }
        
        return vector<string>();
    }
};
// recursive

class Solution {
public:
    unordered_set<string> ans;
    vector<string> removeInvalidParentheses(string s) {
        int left = 0;
        int right = 0;
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='(')  left++;
            else if(s[i]==')'){
                if (left>0) left--;
                else    right++;
            }
        }
        string cur = "";
        helper(0, s, 0, left, right, cur);
        return vector<string>(ans.begin(),ans.end());
    }
    void helper(int pair, string& s, int i, int left, int right,string cur){
        if (i==s.size()){
            if (pair==0 && left==0 && right==0) ans.insert(cur);
            return ;
        }
        
        if (s[i]=='('){
            if (left>0) helper(pair, s, i+1, left-1, right, cur);
            helper(pair+1, s, i+1, left, right, cur+s[i]);
            return ;
        }
            
        if (s[i]==')'){
            if (right>0) helper(pair, s, i+1, left, right-1, cur);
            if (pair>0) helper(pair-1, s, i+1, left, right, cur+s[i]);
            return ;
        }
        
        helper(pair, s, i+1, left, right, cur+s[i]);
    }
};
