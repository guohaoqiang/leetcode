class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size()-1;
        int j = num2.size()-1;
        int carry = 0;
        string ans = "";
        while (i>=0 || j>=0 || carry){
            int s = 0;
            if (i>=0)
                s += num1[i]-'0';
            if (j>=0)
                s += num2[j] -'0';
            s += carry ;
            carry = s/10;
            s %= 10;
            ans += to_string(s);
            i--,j--;
        }
        
        reverse(ans.begin(),ans.end());
        
        return ans;
    }
};
