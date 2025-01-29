class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        int strIndex = 0 , strLen = 1;
        for(int i = 0; i < n; i++){
            for(int j = i; j >= 0; j--){
                if(s[i] == s[j] && (i - j < 2 || dp[j+1][i-1])){
                    dp[j][i] = true;
                    if(i - j + 1 > strLen){
                        strLen = i - j +1;
                        strIndex = j;
                    }
                }
            }
        }
        return s.substr(strIndex,strLen);

    }
};