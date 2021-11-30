//https://leetcode.com/problems/robot-room-cleaner/discuss/153530/DFS-Logical-Thinking

class Solution {
public:
    unordered_map<string,int> tag;
    // up, right, down, left 
    vector<vector<int>> dir = {{-1,0},{0,1},{1,0},{0,-1}};
    void cleanRoom(Robot& robot) {
        dfs(robot, 0, 0, 0);
    }
    
    void dfs(Robot& robot, int x, int y, int d){
        string key = to_string(x) + "#" + to_string(y);
        tag[key]++;
        robot.clean();
        
        for (int i=0; i<4; ++i){
            int xx = x + dir[d][0];
            int yy = y + dir[d][1];
            if (!tag.count(to_string(xx) + "#" + to_string(yy)) && robot.move()){
                dfs(robot, xx, yy, d);
                goback(robot);
            }
            robot.turnRight();
            d = (d+1)%4;
        }
    }
    void goback(Robot& robot){
        robot.turnRight();
        robot.turnRight();
        robot.move();
        robot.turnRight();
        robot.turnRight();
    }
};
