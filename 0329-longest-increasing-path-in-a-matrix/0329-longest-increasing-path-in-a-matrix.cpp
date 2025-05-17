class Solution {
public:
    int dx[4] = {-1,1,0,0};
    int dy[4] = {0,0,1,-1};
    int dfs(vector<vector<int>>& matrix,vector<vector<int>>& dp,int curX,int curY){
        if(dp[curX][curY] != -1){
            return dp[curX][curY];
        }
        int ans = -1;
        for(int d = 0; d < 4; d++){
            int newX = curX + dx[d];
            int newY = curY + dy[d];
            if(newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size()){
                if(matrix[newX][newY] > matrix[curX][curY]){
                    ans = max(ans,dfs(matrix,dp,newX,newY) + 1);
                }
            }
        }
        return dp[curX][curY] = max(ans,1);
    }
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size(),ans = 1;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int i = 0; i < n ; i++){
            for(int j = 0; j < m; j++){
                ans = max(ans,dfs(matrix,dp,i,j));
            }
        }    
        return ans;
    }
};