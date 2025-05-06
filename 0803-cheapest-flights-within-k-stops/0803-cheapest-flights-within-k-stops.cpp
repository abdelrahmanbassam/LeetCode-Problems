class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> costs(n,1e8);
        costs[src] = 0;
        for(int i = 0 ; i <= k; i++){
            vector<int> tmpPrices = costs;
            for(int j = 0; j < flights.size(); j++){
                int s = flights[j][0];
                int d = flights[j][1];
                int c = flights[j][2];

                if(costs[s] != 1e8){
                    tmpPrices[d] = min(tmpPrices[d],c + costs[s]);
                }
            }
            costs = tmpPrices;
        }
        return costs[dst] != 1e8 ? costs[dst] : -1;
    }
};