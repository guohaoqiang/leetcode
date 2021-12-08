//https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/discuss/510263/JavaC%2B%2BPython-Priority-Queue

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(),events.end());
        
        priority_queue<int,vector<int>,greater<int>> pq;
        
        int n = events.size();
        int i = 0;
        int ans = 0;
        for (int d=1; d<=100000; ++d){
            while(!pq.empty() && pq.top()<d){
                // remove events already over
                pq.pop();
            }
            while (i<n && events[i][0]==d){
                // push starting events into the min-heap
                pq.push(events[i++][1]);
            }
            if (!pq.empty()){
                ans++;
                pq.pop();
            }
                
        }
        
        return ans;
    }
};
