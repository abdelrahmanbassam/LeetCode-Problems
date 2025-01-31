class Solution {
private:
    vector<int> dirX = {1, -1, 0, 0};
    vector<int> dirY = {0, 0, 1, -1};
     bool isValid(int r, int c, int n) {
        return r >= 0 && r < n && c >= 0 && c < n;
    }

    int exploreIsland(vector<vector<int>>& grid, int islandId, int row, int col) {
        if (!isValid(row,col,grid.size()) || grid[row][col] != 1)
            return 0;

        grid[row][col] = islandId;
        int size = 1;

        for (int i = 0; i < 4; ++i) {
            size += exploreIsland(grid, islandId, row + dirX[i], col + dirY[i]);
        }

        return size;
    }

public:
    int largestIsland(vector<vector<int>>& grid) {
        unordered_map<int, int> islandSizes;
        int islandId = 2, maxIslandSize = 1;

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 1) {
                    islandSizes[islandId] = exploreIsland(grid, islandId, row, col);
                    ++islandId;
                }
            }
        }

        if (islandSizes.size() == 1) {
            int sz = grid.size() * grid[0].size();
            return (islandSizes[islandId - 1] == sz) ? sz : islandSizes[islandId - 1] + 1;
        }

        for (int row = 0; row < grid.size(); ++row) {
            for (int col = 0; col < grid[0].size(); ++col) {
                if (grid[row][col] == 0) {
                    int newSize = 1;
                    unordered_set<int> neighboringIslands;

                    for (int i = 0; i < 4; ++i) {
                        int newRow = row + dirX[i];
                        int newCol = col + dirY[i];

                        if (isValid(newRow,newCol,grid.size())&& grid[newRow][newCol] > 1) {
                            if (neighboringIslands.insert(grid[newRow][newCol]).second) {
                                 newSize += islandSizes[grid[newRow][newCol]];
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, newSize);
                }
            }
        }

        return maxIslandSize;
    }
};
