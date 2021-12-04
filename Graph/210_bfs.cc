//https://leetcode.com/problems/course-schedule-ii/discuss/59316/C%2B%2B-BFS-and-DFS
//https://leetcode.com/problems/course-schedule-ii/discuss/161141/c%2B%2B-topological-solution
class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> g(numCourses,vector<int>());
        vector<int> indeg(numCourses,0);
        
        //build the graph
        for (auto p:prerequisites){
            g[p[1]].push_back(p[0]);
            indeg[p[0]]++;
        }
        queue<int> q;
        //find the first (root)
        for (int i=0; i<indeg.size(); ++i){
            if (!indeg[i]){
                q.push(i);
                //break;
            }
        }
        
        vector<int> ans;
        int cts = 0;
        while (!q.empty()){
            int top = q.front();
            q.pop();
            
            for (auto subseq:g[top]){
                indeg[subseq]--;
                if (indeg[subseq]==0){
                    q.push(subseq);
                }
            }
            ans.push_back(top);
            cts++;
        }
        return cts==numCourses? ans : vector<int>();
    }
};
