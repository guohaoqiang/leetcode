class Solution {
public:
    string originalDigits(string s) {
        
        vector<int> c(26,0);
        for (auto ch:s){
            c[ch-'a']++;
        }
        vector<int> num(10,0);
        num[0] = c['z'-'a'];
        num[2] = c['w'-'a'];
        num[4] = c['u'-'a'];
        num[6] = c['x'-'a'];
        num[8] = c['g'-'a'];
        num[1] = c['o'-'a']-num[0]-num[2]-num[4];
        num[3] = c['t'-'a']-num[2]-num[8];
        num[5] = c['f'-'a']-num[4];
        num[7] = c['v'-'a']-num[5];
        num[9] = c['i'-'a']-num[5]-num[6]-num[8];
        
        string ans = "";
        for (int i=0; i<10; ++i){
            ans += string(num[i],'0'+i);
        }
        return ans;
    }
};
