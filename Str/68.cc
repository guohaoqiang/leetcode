// https://leetcode.com/problems/text-justification/discuss/633915/Fast-and-thoroughly-explained-c%2B%2B-solution
class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int w) {
        vector<string> ans;
        int j;
        for (int i=0; i<words.size(); i=j){
            
            string s(w,' ');
            s.replace(0, words[i].size(), words[i]);
            
            int remaining = w - words[i].size();
            
            for (j=i+1; j<words.size() && remaining>words[j].size(); ++j){
                remaining -= 1 + words[j].size();
            }
            
            int cnt = j - i - 1;
            
            if (cnt){
                int even_space = 1;
                int uneven_space = 0;
                
                if (j<words.size()){
                    even_space += remaining/cnt;
                    uneven_space += remaining%cnt;
                    
                }
                int index = words[i].size() + even_space + (uneven_space-- >0); 
                for (int k=i+1; k<words.size() && index<w; ++k){
                    s.replace(index,words[k].size(),words[k]);
                    index += words[k].size() + even_space + (uneven_space-- >0);
                }
                
            }
            ans.push_back(s);
        }
        
        return ans;
    }
};
