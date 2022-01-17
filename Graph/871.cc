class Solution {
public:
    int minRefuelStops(int t, int s, vector<vector<int>>& st) {
        
        priority_queue<int> q;
        q.push(s);
        int i = 0;
        int times = 0;
        int stock = 0;
        while (!q.empty()){
            stock += q.top();
            q.pop();
            
            if (stock>=t)   return times;
                
            while (i<st.size() && stock >= st[i][0]){
                q.push(st[i][1]);
                i++;
            }  
            times++;
        }
        
        return -1;
    }
};
