class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProf = 0, curMin = INT_MAX;
        for(auto &p : prices){
            curMin = min(curMin, p);
            maxProf = max(maxProf,p - curMin);
        }
        return maxProf;
    }
};