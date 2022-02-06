class Solution {
public:
    bool isNumber(string s) {
        int e_idx = -1;
        for (int i=0; i<s.size(); ++i){
            if (s[i]=='e' || s[i]=='E'){
                e_idx = i;
                break;
            }
        }
        if (e_idx==-1)  return isdecimal(s) || isinteger(s);
        
        if (!isdecimal(s.substr(0,e_idx)) && !isinteger(s.substr(0,e_idx))) return false;
        if (!isinteger(s.substr(e_idx+1)))    return false;

        return true;
    }
    bool isinteger(string s){
        int i = (s[0]=='+' || s[0]=='-')? 1 : 0;
        if (i==s.size())    return false;
        while (i<s.size()){
            if (!isdigit(s[i])) return false;
            i++;
        }
        return true;
    }
    bool isdecimal(string s){
        int i = (s[0]=='+' || s[0]=='-')? 1 : 0;
        
        int dot = 0;
        int num = 0;
        for (; i<s.size(); ++i){
            if (isdigit(s[i])){
                num++;
            }else if (s[i]=='.'){
                dot++;
            }else
                return false;
        }
        if (dot==1 && num>=1)   return true;
        
        return false;
    }
};
