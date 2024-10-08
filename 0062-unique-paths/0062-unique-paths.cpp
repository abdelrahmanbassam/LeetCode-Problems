class Solution {
public:
    int uniquePaths(int m, int n) {
        if(m==1 || n==1) 
         return 1;
         
        vector<vector<int>> prob(m, vector<int>(n, 1));
        for (int i = 1; i < m; i++) {
            
            for (int j = 1; j < n; j++) {

                prob[i][j] = prob[i][j - 1]+prob[i - 1][j] ;
            }
        }
        return prob[m - 1][n - 1];  
    }
};