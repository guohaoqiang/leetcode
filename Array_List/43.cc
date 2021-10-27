class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0") return "0";
        
        vector<int> tmp(num1.size()+num2.size(),0);
        for (int i=num1.size()-1; i>=0; --i){
            for (int j=num2.size()-1; j>=0; --j){
                tmp[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                tmp[i+j] += tmp[i+j+1]/10;
                tmp[i+j+1] %= 10;
            }
        }
        int m = 0;
        while (tmp[m]==0)   m++;
        string ans="";
        for (int i=m; i<num1.size()+num2.size(); ++i){
            ans += to_string(tmp[i]);
        }
        
        return ans;
    }
};
