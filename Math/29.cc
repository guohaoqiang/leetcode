class Solution {
public:
    
    int divide(int dividend, int divisor) {
        if (dividend==INT_MIN && divisor==-1){
            return INT_MAX;
        }
        
        long a = abs(dividend);
        long b = abs(divisor);
        long ans = 0;
        while(a>=b){
            int ct = 0;
            for (; a - (b<<ct<<1)>=0; ct++){
                
            }
            a -= (b<<ct);
            ans += 1<<ct;
        }
        
        return (dividend>0 == divisor>0)? ans : -ans;
    }
    
};
