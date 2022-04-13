class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        // {val,{idx0,idx1,...}}
        unordered_map<int, vector<size_t>> m;
        for (size_t i=0; i<arr.size(); ++i){
            m[arr[i]].push_back(i);
        }
        
        vector<bool> v(n,false);
        v[0] = true;
        queue<int> q; q.push(0);
        int ans = 0;
        while (!q.empty()){
            for (size_t i=q.size(); i>0; --i){
                int top = q.front();
                q.pop();
                
                if (top==n-1)   return ans;
                if (top>0) m[arr[top]].push_back(top-1);
                if (top<n-1) m[arr[top]].push_back(top+1);
                
                for (auto nb:m[arr[top]]){
                    if (v[nb])   continue;
                    v[nb] = true;
                    q.push(nb);
                }
                m[arr[top]].clear();
            }
            ans++;
        }
        return ans;
    }
};
