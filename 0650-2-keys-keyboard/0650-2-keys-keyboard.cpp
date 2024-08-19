class Solution {
public:
    int dpHelper(vector<vector<int>> &dp, int n,int cur,int copy){
        if(cur > n)
            return 10000;
        if(cur == n)
            return 0;
        
        if(dp[cur][copy] != -1)
            return dp[cur][copy];
        //paste , paste and copy
        int p  = dpHelper(dp,n,cur+copy,copy)+1;
        int pc = dpHelper(dp,n,cur*2,cur)+2;
       
        return dp[cur][copy] = min(p,pc);
    }
    int minSteps(int n) {
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        // dp[1][1] = 0;
        if(n == 1)
            return 0;

        return dpHelper(dp,n,1,1) + 1;  
        // return dp[n];
    }
};