class Solution {
public:
    int findDerangement(int n) {
        long minus_one = 1;
        long minus_two = 0;
        if (n<=1)   return 0;
        if (n==2)   return 1;
        long ans;
        for (int i=3; i<=n; ++i){
            ans = (i-1)*(minus_one+minus_two)%1000000007;
            minus_two = minus_one;
            minus_one = ans;
        }
        return ans;
    }
};
