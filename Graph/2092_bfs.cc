class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        // {a,{{b,tb},{c,tc},...}}
        unordered_map<int,vector<pair<int,int>>> m;
        for (auto p:meetings){
            m[p[0]].push_back({p[1], p[2]});
            m[p[1]].push_back({p[0], p[2]});
        }
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        vector<bool> v(n,false);
        q.push({0,0});
        q.push({0,firstPerson});
        //v.insert(firstPerson);
        //v.insert(0);
        vector<int> ans;
        while (!q.empty()){
            auto top = q.top();
            q.pop();
            if (v[top.second]){
                continue;
            } 
            v[top.second] = true;
            for (auto nb:m[top.second]){
                if (nb.second>=top.first && !v[nb.first]){
                    //ans.push_back(nb.first);
                    q.push({nb.second,nb.first});
                }
            } 
        }
        for (size_t i=0; i<n; ++i){
            if(v[i])    ans.push_back(i);
        }
        return ans;
    }
};
