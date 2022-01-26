class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int> dq;
        vector<long long> p(nums.begin(),nums.end());
        int i=0;
        int ans = INT_MAX;
        while (i<nums.size()){
            if (i>0){
                p[i] += p[i-1];
            }
            if (p[i]>=k)    ans = min(ans,i+1);
            
            while (!dq.empty() && p[i]<p[dq.back()]){
                dq.pop_back();
            }
            
            while (!dq.empty() && p[i]-p[dq.front()]>=k){
                ans = min(ans,i-dq.front());
                dq.pop_front();
            }
            dq.push_back(i);
            i++;
        }
        
        return ans==INT_MAX? -1 : ans;
    }
}
