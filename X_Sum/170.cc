class TwoSum {
public:
    TwoSum() {
        
    }
    
    void add(int number) {
        mp[number]++;
    }
    
    bool find(int value) {
        if (value>up_ || value<low_)    return false;
        for (auto c:mp){
            int p = mp.count(value-c.first);
            if (p && (2*c.first!=value || c.second>=2)){
                return true;
            } 
        }
        return false;
    }
    unordered_map<int,int> mp;
    int low_ = -pow(10,5)*2;
    int up_ = pow(10,5)*2;
};
