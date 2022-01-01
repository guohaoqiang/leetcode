class Solution {
public:
    string multiply(string num1, string num2) {
        if (num1=="0" || num2=="0")
            return "0";
        
        int m = num1.size();
        int n = num2.size();
        vector<int> tmp(m+n,0);
        for (int i=m-1; i>=0; --i){
            for (int j=n-1; j>=0; --j){
                tmp[i+j+1] += (num1[i]-'0')*(num2[j]-'0');
                tmp[i+j] += tmp[i+j+1]/10;
                tmp[i+j+1] = tmp[i+j+1]%10;
            }
        }
        int k = 0; 
        while (!tmp[k]) k++;
        string ans = "";
        for (int i=k; i<m+n; ++i){
            ans += to_string(tmp[i]);
        }
        return ans;
    }
};
