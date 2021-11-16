class Solution {
public:
    int trap(vector<int>& h) {
        int left = 0;
        int right = h.size()-1;
        int mx = 0;
        int sol = 0;
        while (left<=right){
            if (h[left]<h[right]){
                if (h[left]>mx){
                    mx = h[left++];
                }else{
                    sol += (mx-h[left++]);
                }
            }else{
                if (h[right]>mx){
                    mx = h[right--];
                }else{
                    sol += (mx-h[right--]);
                }
            }
        }
        return sol;
    }
};
