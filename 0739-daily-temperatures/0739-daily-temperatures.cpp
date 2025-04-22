class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<pair<int,int>> st;// temp, day;
        int n = temperatures.size();
        vector<int>ans(n,0);
        for(int i = 0 ; i < n; i++){
            while(st.size() && temperatures[i] > st.top().first){
                ans[st.top().second] = i - st.top().second;
                st.pop();
            }
            st.push({temperatures[i],i});
        }
        return ans;
    }
};