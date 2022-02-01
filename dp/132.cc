class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<int> cuts(n+1,0);
        iota(cuts.begin(),cuts.end(),-1);
        // center i
        for (int i=0; i<s.size(); ++i){
            // half length
            for (int j=0; i-j>=0 && i+j<n && s[i-j]==s[i+j]; ++j){
                // odd full length
                cuts[i+j+1] = min(cuts[i+j+1], 1+cuts[i-j]);
            }
            for (int j=1; i-j+1>=0 && i+j<n && s[i-j+1]==s[i+j]; ++j){
                // even full length
                cuts[i+j+1] = min(cuts[i+j+1], 1+cuts[i-j+1]);
            }
        }
        return cuts.back();
    }
};
