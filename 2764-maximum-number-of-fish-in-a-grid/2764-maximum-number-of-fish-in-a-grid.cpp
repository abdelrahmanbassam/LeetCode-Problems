class Solution {
public:
    int dirX[4] = {1,-1,0,0};
    int dirY[4] = {0,0,-1,1};

    bool validMove(int n, int m, int i, int j){
        if(i < n && i >= 0 && j < m && j >= 0)
            return true;
        return false;
    }
    int dfs(vector<vector<int>>& grid,int i ,int j){
        int sum = grid[i][j];    
        grid[i][j] = 0 ;
        for(int d = 0; d < 4; d++){
            int x = i + dirX[d];
            int y = j + dirY[d];
            if(validMove(grid.size(), grid[0].size(), x, y) && grid[x][y])
                sum += dfs(grid,x,y);
        }
        return sum;
    }
    int findMaxFish(vector<vector<int>>& grid) {
        int sum = 0;
        for(int i = 0; i < grid.size(); i++)
            for(int j = 0; j < grid[0].size(); j++)
                if(grid[i][j]){
                    sum = max(sum,dfs(grid,i,j));
                } 
        return sum;
    }
};