class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> temp;
        for (auto s:timePoints){
            temp.push_back(stoi(s.substr(0,2))*60 + stoi(s.substr(3)));
        }
        sort(temp.begin(),temp.end());
        int ans = 24*60;
        temp.push_back(temp[0]+ans);
        for (size_t i=1; i<temp.size(); ++i){
            ans = min(ans, temp[i]-temp[i-1]);
        }
        return ans;
    }
};
