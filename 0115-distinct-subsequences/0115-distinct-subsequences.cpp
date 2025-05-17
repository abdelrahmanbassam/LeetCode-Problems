class Solution {
public:
    int allValidSubs(string &s, string &t,int i, int j , vector<vector<int>> &dp){
        if(i == s.size() || j == t.size()){
            return j == t.size();
        }

        if(s.size() - i < t.size() - j){
            return dp[i][j] = 0;
        }

        if(dp[i][j] != -1){
            return dp[i][j];
        }

        if(s[i] == t[j]){
            dp[i][j] = allValidSubs(s,t,i+1,j+1,dp) + allValidSubs(s,t,i+1,j,dp); 
        }
        else{
            dp[i][j] = allValidSubs(s,t,i+1,j,dp);
        }
        return dp[i][j];

    }
    int numDistinct(string s, string t) {
        int n =s.size(), m = t.size();
        vector<vector<int>>dp(n,(vector<int>(m,-1)));
        return allValidSubs(s,t,0,0,dp);
    }
};