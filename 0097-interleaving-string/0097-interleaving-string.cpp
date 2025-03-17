class Solution {
    vector<vector<int>> dp;

public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) 
            return false;
        dp = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, 0, s1, s2, s3);
    }
    
    bool dfs(int i, int j, int k, string& s1, string& s2, string& s3) {
        if(k == s3.size()){
            return i == s1.size() && j == s2.size();
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        bool found = false;
        if(i < s1.size() && s1[i] == s3[k]){
            found = dfs(i+1,j,k+1,s1,s2,s3);
        }
        if(!found && j < s2.size() && s2[j] == s3[k]){
            found = dfs(i,j+1,k+1,s1,s2,s3);
        }
        return dp[i][j] = found;
    }
};