class Solution {
public:
    int maxhist(vector<int>& h){
        h.push_back(0);
        stack<int> st;
        int ans = 0;
        for (int i=0; i<h.size(); ++i){
            while (!st.empty() && h[i]<h[st.top()]){
                int t = st.top();
                st.pop();
                
                int m = st.empty()? -1 : st.top();
                ans = max(ans, h[t]*(i-m-1));
            }
            st.push(i);
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int ans = 0;
        vector<int> h(n,0);
        for (int i=0; i<m; ++i){
            for (int j=0; j<n; ++j){
                if (matrix[i][j]=='1'){
                    h[j]++;
                }else{
                    h[j] = 0;
                }
            }
            ans = max(ans, maxhist(h));
        }
        
        return ans;
    }
};
