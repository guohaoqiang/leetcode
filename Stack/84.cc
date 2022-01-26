class Solution {
public:
    int largestRectangleArea(vector<int>& h) {
        stack<int> st;
        h.push_back(0);
        int i=0;
        int ans = 0;
        while (i<h.size()){
            while (!st.empty() && h[i]<h[st.top()]){
                int top = st.top();
                st.pop();
                int m = st.empty()? -1 : st.top();
                ans = max(ans, h[top]*(i-m-1));
            }
            st.push(i++);
        }
        return ans;
    }
};
