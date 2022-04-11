// https://leetcode.com/problems/odd-even-jump/discuss/217981/JavaC%2B%2BPython-DP-using-Map-or-Stack

class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<int> hi(n,0), lo(n,0);
        map<int,int> mp;
        mp[arr.back()] = n-1;
        hi[n-1] = 1;
        lo[n-1] = 1;
        int ans = 1;
        for (int i=n-2; i>=0; --i){
            auto h = mp.lower_bound(arr[i]);
            auto l = mp.upper_bound(arr[i]);
            
            if (h!=mp.end()) hi[i] = lo[(*h).second];
            if (l!=mp.begin()) lo[i] = hi[(--l)->second];
            
            if (hi[i])  ans++;
            mp[arr[i]] = i;
        }
        return ans;
        
    }
};
