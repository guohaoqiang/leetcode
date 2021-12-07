class Solution {
public:
    int kthFactor(int n, int k) {
        set<int> d;
        for (int i=1; i<=sqrt(n); ++i){
            if (n%i==0){
                d.insert(i);
                if (i<sqrt(n)){
                    d.insert(n/i);
                }
            }
        }
        if (d.size()<k) return -1;
        auto it = d.begin();
        while (--k>0){
            it++;
        }
        return *it;
    }
};
