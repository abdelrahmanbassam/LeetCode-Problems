class Solution {
public:
    int cycleStart = -1;
    void dfs(int src, vector<bool>&visited, vector<vector<int>>&adjList, vector<int>&parent){
        visited[src] = true;

        for(int adj : adjList[src]){
            if(!visited[adj]){
                parent[adj] = src;
                dfs(adj,visited,adjList,parent);
            }
            else if(cycleStart == -1 && parent[src] != adj){
                cycleStart = adj;
                parent[adj] = src;
            }
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int N = edges.size()+1;

        vector<bool> visited(N, false);
        vector<int> parent(N, -1);

        vector<vector<int>> adjList(N);
        for (auto edge : edges) {
            adjList[edge[0] ].push_back(edge[1] );
            adjList[edge[1] ].push_back(edge[0] );
        }
        dfs(1, visited, adjList, parent);
        unordered_map<int, int> cycleNodes;
        int node = cycleStart;
        do {
            cycleNodes[node] = 1;
            node = parent[node];
        } while (node != cycleStart);

        for (int i = edges.size() -1; i >= 0; i--) {
            if (cycleNodes[edges[i][0] ] && cycleNodes[edges[i][1] ]) {
                return edges[i];
            }
        }
        return {};
    }
};