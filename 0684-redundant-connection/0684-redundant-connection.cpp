class Solution {
public:
    int cycleStart = -1;
    void dfs(int curNode,vector<vector<int>> &adjList, vector<bool> & visited, vector<int> &parent){
        visited[curNode] = true;
        for(auto &child : adjList[curNode]){
            if(!visited[child]){
                parent[child] = curNode;
                dfs(child,adjList,visited,parent);
            }
            else if(cycleStart == -1 && parent[curNode] != child){
                parent[child] = curNode;
                cycleStart = child;
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
        dfs(1,adjList,visited,parent);
        unordered_map<int, bool> cycleNodes;
        cycleNodes[cycleStart] = true;
        int node = parent[cycleStart];
        while(node != cycleStart){
            cycleNodes[node] = true;
            node = parent[node];
        }
        for(int i = edges.size()-1; i >= 0; i--){
            if(cycleNodes[edges[i][0]] && cycleNodes[edges[i][1]])
                return {edges[i][0],edges[i][1]};
        }
        return {};
    }
};