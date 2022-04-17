// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/discuss/414804/A-Review%3A-Why-This-Problem-Is-a-Tip-of-the-Iceberg
// https://leetcode.com/problems/tiling-a-rectangle-with-the-fewest-squares/discuss/414260/8ms-Memorized-Backtrack-Solution-without-special-case

class Solution {
public:
    int ans = INT_MAX;
    unordered_map<int,int> hash;
    int tilingRectangle(int n, int m) {
        if (n>m){
            return tilingRectangle(m, n);
        }
        
        vector<int> h(n+1, 0);
        dfs(n, m, h, 0);
        return ans;
    }
    void dfs(int n, int m, vector<int>& h, int cnt){
        if (cnt>=ans)   return ;
        
        int minH = INT_MAX;
        int minPos = -1;
        long base = m + 1;
        long key = 0;
        for (int i=0; i<n; ++i){
            if (h[i]<minH){
                minH = h[i];
                minPos = i;
            }
            // compute the hash of the current h distribution
            key += h[i]*base;
            base *= (m+1);
        }
        
        // minH is always INT_MAX at the begining of each dfs, thus minH==m when all h[] are m. 
        if (minH==m){
            ans = min(ans, cnt);
            return ;
        }
        
        // the current h[] distribution exists AND its square count is smaller, so it is unnecessary to move on to explore
        if (hash.count(key) && hash[key]<=cnt)  return;
        hash[key] = cnt;
        
        int end = minPos;
        // end+1-minPos is the potential maximum edge (or height) length of new square
        while (end+1<n && h[end+1]==h[minPos] && end+1-minPos+minH<m)  end++;
        
        // from the largest potential square to explore
        for (int j=end; j>=minPos; --j){
            vector<int> new_h(h.begin(), h.end());
            // update the skyline h[] according to the candidate square
            for (int i=minPos; i<=j; ++i){
                new_h[i] += (j-minPos+1);
            }
            dfs(n, m, new_h, cnt+1);
        }
    }
};
