class Solution {
    public:
        vector<int> bobPath;
        int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
            int n = amount.size();
            vector<vector<int>> tree(n);
            vector<int> visited(n, false);
    
            // Build adjacency list
            for (vector<int> edge : edges) {
                tree[edge[0]].push_back(edge[1]);
                tree[edge[1]].push_back(edge[0]);
            }
    
            // Find Bob's path to node 0
            visited[bob] = true;
            findBobPath(bob, visited, tree);
            int szBob = bobPath.size();
            for (int i = 0; i < szBob / 2; i++) {
                amount[bobPath[i]] = 0;
            }
            if (szBob % 2 == 1) { 
                amount[bobPath[szBob / 2]] /= 2;
            }
    
            vector<int> aliceVisited(n, false);
            return maxTreePath(0, amount, tree, aliceVisited);
        }
    
        bool findBobPath(int curNode, vector<int>& visited, vector<vector<int>>& tree) {
            bobPath.push_back(curNode);
            if (curNode == 0) 
                return true; 
    
            for (int adjacentNode : tree[curNode]) {
                if (!visited[adjacentNode]) {
                    visited[adjacentNode] = true;
                    if (findBobPath(adjacentNode, visited, tree)) {
                        return true;
                    }
                }
            }
            bobPath.pop_back();
            return false;
        }
    
        int maxTreePath(int node, vector<int>& amount, vector<vector<int>>& tree, vector<int>& aliceVisited) {
            aliceVisited[node] = true;
            int maxProfit = INT_MIN;
            bool isLeaf = true;
    
            for (int adjacent : tree[node]) {
                if (!aliceVisited[adjacent]) {
                    isLeaf = false;
                    maxProfit = max(maxProfit, maxTreePath(adjacent, amount, tree, aliceVisited));
                }
            }
    
            if (isLeaf) return amount[node]; 
    
            return amount[node] + maxProfit;
        }
    };