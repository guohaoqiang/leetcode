class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int pop[2051] = {0};
        
        for (auto p:logs){
            pop[p[0]]++;
            pop[p[1]]--;
        }
        int ans = 0;
        for (int i=1950; i<=2050; ++i){
            pop[i] += pop[i-1];
            ans = pop[i]>pop[ans]? i : ans;
        }
        
        return ans;
    }
};
