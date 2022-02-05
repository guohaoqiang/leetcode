class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string,string> parent;
        unordered_map<string,string> owner;
        // initialize
        for (auto account:accounts){
            for (int i=1; i<account.size(); ++i){
                parent[account[i]] = account[i];
                owner[account[i]] = account[0];
            }
        }
        
        // update parent
        for (auto account:accounts){
            string p = parent[uf(parent, account[1])];
            for (int i=2; i<account.size(); ++i){
                parent[uf(parent, account[i])] = p;
            }
        }
        
        // collect nodes belonging to the same parent
        unordered_map<string,set<string>> m;
        for (auto account:accounts){
            for (int i=1; i<account.size(); ++i){
                m[uf(parent,account[i])].insert(account[i]);
            }
        }
        
        // final output
        vector<vector<string>> ans;
        for (auto p:m){
            ans.push_back(vector<string>(p.second.begin(),p.second.end()));
            ans.back().insert(ans.back().begin(),owner[p.first]);
        }
        return ans;
    }
    string uf(unordered_map<string,string>& parent, string& s){
        if (parent[s]==s)   return s;
        return uf(parent, parent[s]);
    }
};
