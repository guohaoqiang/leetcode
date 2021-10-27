//https://leetcode.com/problems/meeting-rooms-ii/discuss/278270/JavaC%2B%2BPython-Sort-All-Time-Point

class Solution {
public:
    
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int,int> t;
        for (auto &it:intervals){
            t[it[0]]++;
            t[it[1]]--;
        }
        int ans = 0;
        int cur = 0;
        for (auto &it:t){
            ans = max(ans, cur += it.second);
        }
        return ans;
    }
};
