class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& t) {
        stack<int>dec;
        int n = t.size();
        vector<int>ans(n,0);
        for(int i = 0; i < n;i++){
            while(!dec.empty() && t[i] > t[dec.top()]){
                int ind = dec.top();
                dec.pop();
                ans[ind] = i - ind;
            }
            dec.push(i);
        }
        return ans;
    }
};