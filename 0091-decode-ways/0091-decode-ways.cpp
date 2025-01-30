class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        vector<int> dp (n + 1);
        
        dp[0] = 1;
        dp[1] = s[0] != '0';

        for(int i = 2 ; i <= n; i++){
            int d1 = s[i - 1] - '0';
            int d2 = (s[i - 2] - '0')*10 + d1;
            bool v1 = d1 != 0;
            bool v2 = d2 < 27 && d2 > 9;

            if(v1 && v2)
                dp[i] = dp[i - 2] + dp[i - 1];
            else if(v1)
                dp[i] = dp[i - 1];
            else if(v2)
                dp[i] = dp[i - 2];
                // cout<<"here" ;
        }
        return dp[n];
    }
};