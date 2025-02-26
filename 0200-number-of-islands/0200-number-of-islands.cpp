class Solution {
public:
    int dirX[4] = {1,-1,0,0};
    int dirY[4] = {0,0,-1,1};
    bool vaildMove(int i, int j, int n, int m){
        return(i >= 0 && i < n && j >= 0 && j < m);
    }
    void dfs(int i, int j,vector<vector<bool>> &visited,vector<vector<char>>& grid){
        for(int k = 0; k < 4; k ++){
            int x = dirX[k] + i;
            int y = dirY[k] + j;
            if(vaildMove(x,y,grid.size(),grid[0].size()) && grid[x][y] == '1' && !visited[x][y]){
                visited[x][y] = true;
                dfs(x,y,visited,grid);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        int islands = 0;
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>>visited(n,vector<bool> (m,false));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                   islands++;
                   dfs(i,j,visited,grid); 
                }
            }
        }
        return islands;
    }
};