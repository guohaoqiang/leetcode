//https://leetcode.com/problems/integer-to-english-words/discuss/70651/Fairly-Clear-4ms-C%2B%2B-solution

class Solution {
public:
    string numberToWords(int num) {
        if (num==0) return "Zero";
        
        return to_string(num).substr(1);
        
    }
    string to_string(int num){
        vector<string> below_20 = {"One", "Two", "Three", "Four","Five","Six","Seven","Eight","Nine","Ten", "Eleven","Twelve","Thirteen","Fourteen","Fifteen","Sixteen","Seventeen","Eighteen","Nineteen"};
        vector<string> below_100 = {"Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
        
        if (num>=1000000000) return to_string(num/1000000000) + " Billion" + to_string(num%1000000000);
        else if(num>=1000000) return to_string(num/1000000) + " Million" + to_string(num%1000000);
        else if(num>=1000) return to_string(num/1000) + " Thousand" + to_string(num%1000);
        else if(num>=100) return to_string(num/100) + " Hundred" + to_string(num%100);
        else if(num>=20) return " " + below_100[num/10-2] + to_string(num%10);
        else if(num>=1) return " " + below_20[num-1];
        else return "";
    }
};
