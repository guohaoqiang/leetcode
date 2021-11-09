class Solution {
public:
    vector<string> dict{"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size()==0)   return ans;
        queue<pair<string,int>> q;
        q.push({"",0});
        
        while (!q.empty()){
            auto cur = q.front();
            q.pop();
            
            if (cur.first.size()==digits.size()){
                ans.push_back(cur.first);
                continue;
            }
            
            for (auto c:dict[digits[cur.second]-'2']){
                q.push({cur.first+c,cur.second+1});
            }
        }
        
        return ans;
    }
};
