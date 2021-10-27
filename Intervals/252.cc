class Solution {
public:
    bool canAttendMeetings(vector<vector<int>>& intervals) {
        map<int,int> t;
        
        for (auto &it:intervals){
            t[it[0]]++;
            t[it[1]]--;
        }
        int attend = 0;
        for (auto &it:t){
            attend += it.second;
            if (attend>1)   return false;
        }
        return true;
    }
};
