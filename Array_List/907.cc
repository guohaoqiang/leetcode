//https://leetcode.com/problems/sum-of-subarray-minimums/discuss/170750/JavaC%2B%2BPython-Stack-Solution
class Solution {
public:
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();
        
        stack<pair<int,int>> left,right;
        vector<int> l(n),r(n);
        int count;
        for (int i=0; i<n; ++i){
            count = 1;
            while (!left.empty() && left.top().first>arr[i]){
                count += left.top().second;
                left.pop();
            }
            left.push({arr[i],count});
            l[i] = count;
        }
        for (int i=n-1; i>=0; --i){
            count = 1;
            while (!right.empty() && right.top().first>=arr[i]){
                count += right.top().second;
                right.pop();
            }
            right.push({arr[i],count});
            r[i] = count;
        }
        
        int ans = 0;
        for (int i=0; i<n; ++i){
            ans = (ans + (long)arr[i]*l[i]*r[i])%mod;
        }
        return ans;
    }
};
