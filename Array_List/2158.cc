// https://leetcode.com/problems/amount-of-new-area-painted-each-day/discuss/1741258/C%2B%2B-Simple-solution-with-a-set

class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        vector<int> ans(paint.size(),0);
        int line[500001] = {0};
        for (int i=0; i<paint.size(); ++i){
            int begin = paint[i][0], end = paint[i][1];
            while (begin<end){
                int jump = max(line[begin], begin+1);
                ans[i] += (line[begin]==0);
                line[begin] = max(line[begin], end);
                begin = jump;
            }
        }
        return ans;
    }
};
