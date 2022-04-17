class Solution {
public:
    bool judgePoint24(vector<int>& cards) {
        vector<double> vec(cards.begin(), cards.end());
        return dfs(vec);
    }
    
    bool dfs(vector<double>& vec){
        if (vec.size()==1){
            if (abs(vec[0]-24.0)<1e-4){
                return true;
            }
        }
        for (size_t i=0; i<vec.size(); ++i){
            for (size_t j=i+1; j<vec.size(); ++j){
                vector<double> res;
                generate(vec[i], vec[j], res);
                
                vector<double> sub;
                for (size_t k=0; k<vec.size(); ++k){
                    if (k==i || k==j)   continue;
                    sub.push_back(vec[k]);
                }
                
                for (auto pRes:res){
                    sub.push_back(pRes);
                    if (dfs(sub))   return true;
                    sub.pop_back();
                }
            }
        }
        
        return false;
    }
    void generate(double a, double b, vector<double>& out){
        out.push_back(a+b);
        out.push_back(a*b);
        out.push_back(a-b); 
        out.push_back(a/b);
        if (a!=b){
            out.push_back(b-a); 
            out.push_back(b/a);
        }
    }
};
