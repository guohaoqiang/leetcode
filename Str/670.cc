class Solution {
public:
    int maximumSwap(int num) {
        string s = to_string(num);
        int mx = -1, maxid = -1;
        int left = -1, right = -1;
        
        for (int i=s.size()-1; i>=0; --i){
            if (s[i]>mx){
                mx = s[i];
                maxid = i;
                continue;
            }
            if (s[i]<mx){
                left = i;
                right = maxid;
            }
        }
        
        if (left!=-1 && right!=-1){
            swap(s[left],s[right]);
        }
        return stoi(s);
    }
};
