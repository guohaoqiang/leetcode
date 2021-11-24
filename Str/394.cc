class Solution {
public:
    string decodeString(string s) {
        int i = 0;
        return parse(s,i);
    }
    string parse(const string& s, int& i){
        string ans = "";
        while (i<s.size() && s[i]!=']'){
            if (!isdigit(s[i])){
                ans += s[i++];
            }else{
                int k = 0;
                while (i<s.size() && isdigit(s[i])){
                    k = k*10 + (s[i++] - '0');
                }
                i++;
                string temp = parse(s,i);
                i++;
                while (k-->0){
                    ans += temp;
                }
            }
        }
        return ans;
    }
};
