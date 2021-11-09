//https://leetcode.com/problems/largest-rectangle-in-histogram/discuss/732697/44ms-Easy-Solution-or-C%2B%2B
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        // stores the highest one previously in ascending order
        stack<int> st;
        heights.push_back(0);
        
        int ans = 0;
        for (int i=0; i<heights.size(); ++i){
            while (!st.empty() && heights[i]<heights[st.top()]){
                int top = st.top();
                st.pop();
                int w = st.empty()? -1 : st.top();
                ans = max(ans,heights[top]*(i-w-1));
            }
            st.push(i);
        }
        
        return ans;
    }
};
