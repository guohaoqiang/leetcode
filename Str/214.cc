class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.begin(),rev.end());
        
        rev = s + '#' + rev;
        vector<int> tab(rev.size(),0);
        int k = 0;
        for (int i=1; i<rev.size(); ++i){
            if (rev[i]==rev[k]){
                tab[i] = tab[i-1] + 1;
                k++;
            }else{
                k = tab[i-1]; 
                while (k>0 && rev[i]!=rev[k]){
                    k = tab[k-1];
                }
                if (rev[i]==rev[k]){
                    k++;
                }
                tab[i] = k;
            }
        }
        string temp = s.substr(tab.back());
        reverse(temp.begin(),temp.end());
        return temp+s;
    }
};
