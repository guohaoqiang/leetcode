// https://leetcode.com/problems/subdomain-visit-count/discuss/121738/C%2B%2BJavaPython-Easy-Understood-Solution
class Solution {
public:
    void helper(string& s, unordered_map<string,int>& mp){
        int num = 0;
        int space = -1;
        int first_dot = -1;
        int second_dot = -1;
        for (int i=0; i<s.size(); ++i){
            if (isdigit(s[i])){
                num = num*10 + (s[i] - '0');
            }
            if (s[i] == ' '){
                space = i; 
            }
            if (s[i] == '.' && first_dot==-1){
                first_dot = i;
            }else if (s[i] == '.' && first_dot!=-1){
                second_dot = i;
            }
        }
        mp[s.substr(space+1)] += num;
        mp[s.substr(first_dot+1)] += num;
        if (second_dot!=-1) mp[s.substr(second_dot+1)] += num;
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        vector<string> ans;
        
        unordered_map<string,int> counts;
        for (auto str:cpdomains){
            helper(str,counts);
        }
        
        for (auto it:counts){
            ans.push_back(to_string(it.second)+' '+it.first);
        }
        return ans;
    }
};
