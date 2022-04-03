class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recs, vector<vector<string>>& ingrts, vector<string>& sup) {     
        unordered_map<string,vector<string>> mp;
        unordered_map<string,size_t> cnt;
        for (size_t i=0; i<ingrts.size(); ++i){
            for (auto s:ingrts[i]){
                mp[s].push_back(recs[i]);
                cnt[recs[i]]++;
            }
        }
        
        queue<string> q;
        for (auto s:sup){
            q.push(s);
        }
        
        vector<string> ans;
        while (!q.empty()){
            string top = q.front();
            q.pop();
            
            for (auto s:mp[top]){
                if (--cnt[s]==0){
                    q.push(s);
                    ans.push_back(s);
                }
            }
        }
        
        return ans;
    }
};
