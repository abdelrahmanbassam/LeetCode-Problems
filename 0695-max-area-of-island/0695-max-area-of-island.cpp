class Solution {
public:
    int dirX[4]={0,0,1,-1};
    int dirY[4]={1,-1,0,0};
    int dfs (int x,int y,vector<vector<int>>& grid,int &islands){
        for(int i = 0; i < 4; i ++){
            int newX = dirX[i] + x;
            int newY = dirY[i] + y;
            if(newX >= 0 && newX < grid.size() && newY >= 0 && newY < grid[0].size()){
                if(grid[newX][newY]){
                    grid[newX][newY] = 0;
                    islands++;
                    dfs(newX,newY,grid,islands);
                }        
            }

        }
        return islands;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int maxArea = 0;
        for(int i = 0; i < grid.size(); i++ ){
            for(int j = 0; j < grid[0].size(); j++){
                if(grid[i][j] == 1){
                    int islands = 1;
                    grid[i][j] = 0;
                    dfs(i,j,grid,islands);
                    maxArea = max(maxArea,islands);
                }
            }
        }
        return maxArea;
    }
};