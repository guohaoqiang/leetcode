//https://leetcode.com/problems/car-fleet-ii/discuss/1085987/JavaC%2B%2BPython-O(n)-Stack-Solution
class Solution {
public:
    vector<double> getCollisionTimes(vector<vector<int>>& cars) {
        int n = cars.size();
        vector<double> ans(n,-1);
        stack<int> idx;
        
        for (int i=n-1; i>=0; --i){
            while (!idx.empty()){
                int p = idx.top();
                if (cars[p][1]>=cars[i][1] || 1.0*(cars[p][0]-cars[i][0])/(cars[i][1]-cars[p][1])>=ans[p] && ans[p]>0){
                    idx.pop();
                }else{
                    break;
                }
            }
            if (!idx.empty()){
                ans[i] = 1.0*(cars[idx.top()][0]-cars[i][0])/(cars[i][1]-cars[idx.top()][1]);
            }
            idx.push(i);
        }
        
        return ans;
    }
};
