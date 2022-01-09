class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& p, vector<int>& c) {
        priority_queue<int> pf;
        // {capital, profit}
        multiset<pair<int,int>> rem;
        
        int n = p.size();
        for (int i=0; i<n; ++i){
            if (c[i]<=w){
                pf.push(p[i]);
            }else{
                rem.insert({c[i],p[i]});
            }
        }
        
        while (k-- && !pf.empty()){
            w += pf.top();
            pf.pop();
            
            for (auto it=rem.begin(); it!=rem.end() && (*it).first<=w; it = rem.erase(it)){
                
                pf.push((*it).second);
                
            }
        }
        
        return w;
    }
};
