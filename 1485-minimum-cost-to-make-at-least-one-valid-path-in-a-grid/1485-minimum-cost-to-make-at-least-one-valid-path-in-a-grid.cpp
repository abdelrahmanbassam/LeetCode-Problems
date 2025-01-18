class Solution {
public:
    int directions[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size(), cols = grid[0].size();
        
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        vector<vector<int>> costMatrix(rows, vector<int>(cols, INT_MAX));
        costMatrix[0][0] = 0;

        while (!pq.empty()) {
            auto current = pq.top();
            pq.pop();
            int currentCost = current[0], x = current[1], y = current[2];

            if (costMatrix[x][y] != currentCost) continue;

            for (int i = 0; i < 4; i++) {
                int nextX = x + directions[i][0];
                int nextY = y + directions[i][1];

                if (nextX >= 0 && nextX < rows && nextY >= 0 && nextY < cols) {
                    int updatedCost = currentCost + (i != (grid[x][y] - 1) ? 1 : 0);

                    if (costMatrix[nextX][nextY] > updatedCost) {
                        costMatrix[nextX][nextY] = updatedCost;
                        pq.push({updatedCost, nextX, nextY});
                    }
                }
            }
        }

        return costMatrix[rows - 1][cols - 1];
    }
};
