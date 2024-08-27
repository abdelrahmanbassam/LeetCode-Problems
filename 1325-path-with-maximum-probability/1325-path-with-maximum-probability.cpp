class Solution {
public:
    double dijkstra(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node){
        vector<vector<pair<int,double>>> graph(n);
        for(int i=0;i<edges.size();i++){
            graph[edges[i][0]].push_back({edges[i][1],succProb[i]});
            graph[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        vector<double> dist(n,0);
        vector<bool> visited(n,false);
        dist[start_node] = 1;
        priority_queue<pair<double,int>> pq;
        pq.push({1,start_node});
        while(!pq.empty()){
            auto [prob,node] = pq.top();
            pq.pop();
            if(visited[node]) continue;
            visited[node] = true;
            for(auto [neighbour,neighbour_prob]:graph[node]){
                if(dist[neighbour] < dist[node]*neighbour_prob){
                    dist[neighbour] = dist[node]*neighbour_prob;
                    pq.push({dist[neighbour],neighbour});
                }
            }
        }
        return dist[end_node];
    }
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        return dijkstra(n,edges,succProb,start_node,end_node);  
    }
};