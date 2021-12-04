class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses,vector<int>());
        vector<int> indeg(numCourses,0);
        
        //build the graph
        for (auto p:prerequisites){
            // all p[0] goes after p[1]
            g[p[1]].push_back(p[0]);
            // # of courses goes before p[0]
            indeg[p[0]]++;
        }
        
        queue<int> q;
        //find the first(root)
        for (int i=0; i<numCourses; ++i){
            if (indeg[i]==0){
                q.push(i);
            }
        }
        
        vector<int> ans;
        while (!q.empty()){
            int top = q.front();
            q.pop();
            
            for (auto adj:g[top]){
                indeg[adj]--;
                if(indeg[adj]==0){
                    q.push(adj);
                }
            }
            
            ans.push_back(top);
        }
        
        return ans.size()==numCourses;
    }
};
