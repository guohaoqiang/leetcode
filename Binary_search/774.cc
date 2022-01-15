class Solution {
public:
    double minmaxGasDist(vector<int>& sts, int k) {
        double i = 0;
        double j = sts.back() - sts[0];
        
        while (i+1e-6<j){
            double mid = (i+j)/2;
            int cur = 0;
            for (int p=0; p<sts.size()-1; ++p){
                cur += ceil((sts[p+1]-sts[p])/mid)-1;
                if (cur>k)  break;
            }
            
            if (cur>k){
                i = mid;
            }else{
                j = mid;
            }
        }
        
        return j;
    }
};
