class Solution {
public:
    string shortestCommonSupersequence(string s1, string s2) {
        int n = s1.size(),m = s2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for(int i = 1 ; i <= n; i++){
            dp[i][0] = i;
        }
        for(int j = 1 ; j <= m; j++){
            dp[0][j] = j;
        }
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                if(s1[i-1] == s2[j-1]){
                    dp[i][j] = dp[i-1][j-1] + 1;
                }
                else{
                    dp[i][j] = min(dp[i][j-1],dp[i-1][j]) + 1;
                }
            }
        }
        string supersequence ="";
        int row = n, col = m;
        while(row > 0 && col > 0){
            // if(dp[row][col] == dp[row - 1][col - 1] + 1){
            if(s1[row - 1] == s2[col - 1]){
                supersequence += s1[row - 1];
                row--;
                col--;
            }
            else if (dp[row][col] == dp[row - 1][col] + 1){
                supersequence += s1[row - 1];
                row--;
            }
            else{
                supersequence += s2[col - 1];
                col--;
            }
        }
        while(col > 0){
            supersequence += s2[col - 1];
                col--;
        }
        while(row > 0){
            supersequence += s1[row - 1];
                row--;
        }
        reverse(supersequence.begin(), supersequence.end());
        return supersequence;
    }
};