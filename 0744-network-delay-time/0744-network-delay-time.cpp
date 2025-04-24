class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int,vector<pair<int,int>>> adj;
        for(auto &t : times){
            adj[t[0]].push_back({t[1],t[2]});
        }
        priority_queue <pair<int,int>, vector<pair<int,int>>, greater<>> minHeap;
        minHeap.push({0,k});
        vector<int> cost(n+1,INT_MAX);
        cost[k] = 0;
        while(minHeap.size()){
            auto [parentCost,parentNode] = minHeap.top();
            minHeap.pop();
            for(auto &edge : adj[parentNode]){
                int totalCost = edge.second + parentCost;
                if(totalCost < cost[edge.first]){
                    cost[edge.first] = totalCost;
                    minHeap.push({totalCost,edge.first}); 
                }
            } 
        }
        int maxCost = INT_MIN;
        for(int i = 1; i < cost.size(); i++){
            maxCost = max(maxCost,cost[i]);
        }
        return maxCost != INT_MAX ? maxCost : -1;
    }
};