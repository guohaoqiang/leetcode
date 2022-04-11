class Solution {
public:
    vector<int> dir = {-1,0,1,0,-1};
    int minArea(vector<vector<char>>& image, int x, int y) {
        int m = image.size();
        int n = image[0].size();
        int x1 = x, x2 = x;
        int y1 = y, y2 = y;
        
        queue<pair<int,int>> q;
        unordered_set<int> v;
        q.push({x,y});
        v.insert(x*n+y);
        
        while (!q.empty()){
            int sz = q.size();
            for (size_t i=0; i<sz; ++i){
                auto top = q.front();
                q.pop();
                
                for (size_t k=0; k<4; ++k){
                    int xx = top.first + dir[k];
                    int yy = top.second + dir[k+1];
                    
                    if (xx<0 || xx>=m || yy<0 || yy>=n || v.count(xx*n+yy) || image[xx][yy]=='0') continue;
                    
                    x1 = min(x1, xx);
                    x2 = max(x2, xx);
                    y1 = min(y1, yy);
                    y2 = max(y2, yy);
                    q.push({xx,yy});
                    v.insert(xx*n+yy);
                }
            }
        }
        
        return (x2-x1+1)*(y2-y1+1);
    }
};
