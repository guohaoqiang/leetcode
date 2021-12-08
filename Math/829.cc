//https://leetcode.com/problems/consecutive-numbers-sum/discuss/128947/JavaC%2B%2BPython-Fastest-Count-Odd-Factors-O(logN)
class Solution {
public:
    int consecutiveNumbersSum(int n) {
        int ans = 0;
        for (int i=1; i<=sqrt(2*n); ++i){
            if ((2*n%i==0) && (2*n/i-i-1)%2==0){
                ans++;
            }
        }
        return ans;
    }
};
