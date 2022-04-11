// https://leetcode.com/problems/range-module/discuss/108912/C%2B%2B-vector-O(n)-and-map-O(logn)-compare-two-solutions

class RangeModule {
public:
    RangeModule() {
    }
    
    void addRange(int left, int right) {
        auto l = m.upper_bound(left);
        auto r = m.upper_bound(right);
        if (l!=m.begin()){
            l--;
            if (l->second<left)  l++;
        }
        if (l==r){
            m[left] = right;
            return ;
        }
        left = min(l->first, left);
        right = max((--r)->second, right);
        m.erase(l,++r); // just to recover r, since r decreased by 1 in the 18-th line
        m[left] = right;
    }
    
    bool queryRange(int left, int right) {
        auto it = m.upper_bound(left);
        if (it == m.begin() || (--it)->second<right)    return false;
        return true;
    }
    
    void removeRange(int left, int right) {
        auto l = m.upper_bound(left);
        auto r = m.upper_bound(right);
        if (l!=m.begin()){
            l--;
            if (l->second<left)  l++;
        }
        if (l==r){
            return ;
        }
        int l1 = min(l->first, left);
        int r1 = max((--r)->second, right);
        m.erase(l,++r);
        if (l1<left) m[l1] = left;
        if (r1>right) m[right] = r1;
    }
    map<int,int> m;
};
