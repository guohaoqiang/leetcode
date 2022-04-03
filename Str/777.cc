class Solution {
public:
    bool canTransform(string start, string end) {
        string s1, s2;
        for (auto ch:start){
            if (ch!='X')    s1 += ch;
        }
        for (auto ch:end){
            if (ch!='X')    s2 += ch;
        }
        if (s1!=s2) return false;
        
        size_t i=0, j=0;
        
        while (i<start.size() && j<end.size()){
            if (start[i]=='X'){
                i++;
            }else if (end[j]=='X'){
                j++;
            }else{
                if ((start[i]=='L' && i<j) || (start[i]=='R' && i>j))   return false;
                i++, j++;
            }
        }
        return true;
    }
};
