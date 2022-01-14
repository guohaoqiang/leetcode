class Solution {
public:
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int left = 1;
        int right = 1e9/(k+1);
        
        while (left<right){
            int mid = (left+right+1)/2;
            int cur = 0;
            int cuts = 0;
            for (auto sweet:sweetness){
                cur += sweet;
                if (cur>=mid){
                    cuts++;
                    cur = 0;
                    if (cuts>k){
                        break;
                    }
                }
            }
            if (cuts>k){
                left = mid;
            }else{
                right = mid - 1;
            }
        }
        return right;
    }
};
