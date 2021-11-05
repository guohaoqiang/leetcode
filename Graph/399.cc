class Solution {
public:
    double dfs(string a, string b, unordered_set<string>& v, unordered_map<string,unordered_map<string,double>>& g){
        // w/o a
        if (g.find(a)==g.end()){
            return -1;
        }
        
        //b is the direct neighbor of a
        if (g[a].find(b)!=g[a].end()){
            return g[a][b];
        }
        v.insert(a);
        for (auto& nb:g[a]){
            if (find(v.begin(),v.end(),nb.first)!=v.end()){
                continue;
            }
            v.insert(nb.first);
            double tmp = dfs(nb.first, b, v, g);
            if (tmp!=-1){
                return tmp*g[a][nb.first];
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,unordered_map<string,double>> g;
        int n = equations.size();
        for (int i=0; i<n; ++i){
            g[equations[i][0]][equations[i][1]] = values[i];
            g[equations[i][0]][equations[i][0]] = 1.0;
            g[equations[i][1]][equations[i][1]] = 1.0;
            g[equations[i][1]][equations[i][0]] = 1.0/values[i];
        }
        
        unordered_set<string> visited;
        int len = queries.size();
        vector<double> ans;
        for (int i=0; i<len; ++i){
            visited = {queries[i][0]};
            ans.push_back(dfs(queries[i][0],queries[i][1],visited,g));
        }
        
        return ans;
    }
};
