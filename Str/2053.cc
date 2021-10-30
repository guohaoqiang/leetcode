class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string,int> counts;
    
        for (int i=0; i<arr.size(); ++i){
            counts[arr[i]]++;
        }
        int kk = 0;
        for (auto s:arr){
            if (counts[s]==1){
                kk++;
            }
            if (kk==k){
                return s;
            }
        }
        return "";
    }
};
