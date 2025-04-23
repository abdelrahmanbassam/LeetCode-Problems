class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int curMin = INT_MAX;
        for(auto &p : prices){
            if(p > curMin){
                profit += p - curMin;
                curMin = INT_MAX;
            }
            curMin = min(curMin,p);
        }
        return profit;
    }
};