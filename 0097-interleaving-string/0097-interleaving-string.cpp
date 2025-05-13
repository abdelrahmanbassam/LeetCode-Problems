class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int m = s1.length(), n = s2.length();
        if (m + n != s3.length()) 
            return false;
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        return dfs(0, 0, 0, s1, s2, s3, dp);
    }
    bool dfs(int i,int j,int x,string &s1,string &s2,string &s3,vector<vector<int>> &dp){
        if(x == s3.size())
            return true;
        if(dp[i][j] != -1)
            return dp[i][j];
        bool found = false;
        if(i < s1.size() && s1[i] == s3[x]){
            found = dfs(i+1,j,x+1,s1,s2,s3,dp);
        }
        if(!found && j < s2.size() && s2[j] == s3[x]){
            found = dfs(i,j+1,x+1,s1,s2,s3,dp);
        }
        return dp[i][j] = found;
    }
};