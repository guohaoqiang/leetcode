class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int i = 1;
        int j = 1e9;
        
        while (i<j){
            int mid = (i+j)/2;
            int cur = 0;
            for (auto b:piles){
                cur += (b+mid-1)/mid;
            }
            // Binary search
            if (cur>h){
                i = mid + 1;
            }else{
                j = mid;
            }
        }
        return i;
        
    }
};
