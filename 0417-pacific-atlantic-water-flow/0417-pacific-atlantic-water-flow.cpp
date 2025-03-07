class Solution {
public:
    int dirx[4] = {1,-1,0,0};
    int diry[4] = {0,0,1,-1};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& h) {
        int n = h.size(),m = h[0].size();

        vector<vector<bool>> pac(n, vector<bool>(m, false));
        vector<vector<bool>> atl(n, vector<bool>(m, false));
        vector<vector<int>> ans;
        for(int i = 0; i < n; i++){
            dfs(i,0,pac,h);
            dfs(i,m-1,atl,h);
        }
        for(int i = 0; i < m; i++){
            dfs(0,i,pac,h);
            dfs(n-1,i,atl,h);
        }
        for(int i = 0; i < n; i++){
            for(int j = 0 ; j < m; j++){
                if(pac[i][j] && atl[i][j])
                    ans.push_back({i,j});
            }
        }
        return ans;
    }
    void dfs(int x,int y,vector<vector<bool>> &ocean ,vector<vector<int>>& h){
        ocean[x][y] = 1;
        for(int i = 0; i < 4; i++){
            int nx = x + dirx[i];
            int ny = y + diry[i];
            if(nx >= 0 && nx < h.size() && ny >= 0 && ny < h[0].size()){
                if(h[nx][ny] >= h[x][y] && !ocean[nx][ny]){
                    dfs(nx,ny,ocean,h);
                }
            }
        } 
    }

};