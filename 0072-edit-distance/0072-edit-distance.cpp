class Solution {
public:
    int minOpeartions(string &s, string &t,int i, int j , vector<vector<int>> &dp){
        if(i == s.size()){
            return t.size() - j;
        }
        if(j == t.size()){
            return s.size() - i;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int insertCost,deleteCost,replaceCost;
        if(s[i] == t[j]){
            return dp[i][j] = minOpeartions(s,t,i+1,j+1,dp);
        }
        else{
            insertCost = 1+ minOpeartions(s,t,i,j+1,dp);
            deleteCost = 1+ minOpeartions(s,t,i+1,j,dp);
            replaceCost = 1+ minOpeartions(s,t,i+1,j+1,dp);
        }
        return dp[i][j] = min(insertCost,min(deleteCost,replaceCost));
    }
    int minDistance(string word1, string word2) {
        int n =word1.size(), m = word2.size();
        vector<vector<int>>dp(n,(vector<int>(m,-1)));
        
        return minOpeartions(word1,word2,0,0,dp);
    }
};