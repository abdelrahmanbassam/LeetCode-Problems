class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        priority_queue<pair<int,int> , vector<pair<int,int>>, greater<>> minHeap;
        vector<int> minCost(n,INT_MAX);
        vector<bool> inMST(n,0); 
        minHeap.push({0, 0});
        minCost[0] = 0;
        int totalCost = 0;
        int edgesCount = 0;
        while(minHeap.size()){
            auto [parentCost,parentNode] = minHeap.top();
            minHeap.pop();
            if (inMST[parentNode]) 
                continue;
            inMST[parentNode] = true;
            totalCost += parentCost;
            edgesCount++;

            for(int i = 0; i < n; i++){
                int dist  = abs(points[i][0] - points[parentNode][0]) +  abs(points[i][1] - points[parentNode][1]);
                if(dist < minCost[i]){
                    minCost[i] = dist;
                    minHeap.push({dist,i});
                }

            }
        }
        return totalCost;

    }
};