class Solution {
public:
    int maxArea(vector<int>& h) {
        int i = 0;
        int j = h.size() - 1;
        int ans = 0;
        while (i<j){
            if (h[i]<h[j]){
                ans = max(h[i]*(j-i),ans);
                i++;
            }else{
                ans = max(h[j]*(j-i),ans);
                j--;
            }
        }
        return ans;
    }
};
