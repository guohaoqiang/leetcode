class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        if (finalSum%2) return {};
        
        vector<long long> ans;
        long long cur = finalSum;
    
        if (backtracking(cur, finalSum, ans, 2))   return ans;
        
        return {};
    }
    bool backtracking(long long cur, long long tgt, vector<long long>& ans, long long k){
        
        if (cur==0){
            return true;
        }
        if (cur<0 || k>cur) return false;
        
        for (long long i=k; i<=tgt; i+=2){
            cur -= i;
            ans.push_back(i);
            if (backtracking(cur, tgt, ans, i+2))    return true;
            ans.pop_back();
            cur += i;
        }
        return false;
    }
};
