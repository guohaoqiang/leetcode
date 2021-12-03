class Solution {
public:
    static bool cmp(string a, string b){
        int i = a.find(' ');
        int j = b.find(' ');
        
        string id1 = a.substr(0,i);
        string id2 = b.substr(0,j);
        string ct1 = a.substr(i+1,a.size());
        string ct2 = b.substr(j+1,b.size());
        
        if (!isdigit(ct1[0]) && isdigit(ct2[0]))   return true;
        else if (isdigit(ct1[0]) && !isdigit(ct2[0]))   return false;
        else if (!isdigit(ct1[0]) && !isdigit(ct2[0])){
            if (ct1==ct2)   return id1<id2;
            else    return ct1<ct2;
        }
        return false;
    }
    vector<string> reorderLogFiles(vector<string>& logs) {
        stable_sort(logs.begin(),logs.end(),cmp);
        return logs;
    }
};
