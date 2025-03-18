class Solution {
    public:
        int largestRectangleArea(vector<int>& h) {
            int maxArea = 0;
            stack<pair<int, int>> st;
            int n = h.size(); 
            for(int i = 0; i < n; i++){
                int start = i;
                while(st.size() && h[i] <= st.top().second){
                    pair<int, int> cur = st.top();
                    st.pop();
                    maxArea = max(maxArea,cur.second * (i - cur.first ));
                    start = cur.first;
                }
                st.push({start,h[i]});
            }
            while(st.size()){
                pair<int,int> cur = st.top();
                st.pop();
                maxArea = max(maxArea,cur.second * (n - cur.first));
            }
            return maxArea;
        }
};