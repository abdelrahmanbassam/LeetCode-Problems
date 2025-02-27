
class Solution {
    public:
        int lenLongestFibSubseq(vector<int>& arr) {
            int n = arr.size();
            unordered_map <int,int> valueToIndx;
            for(int i = 0 ; i < n; i++){
                valueToIndx[arr[i]] = i;
            }
        
            vector<vector<int>> dp(n,vector<int> (n,2));
            int ans = 0;
            for(int i = 2; i < n; i++){
                for(int j = i - 1; j >= 0 ; j--){
                    int needed = arr[i] - arr[j];
                    if(valueToIndx.find(needed) != valueToIndx.end() && valueToIndx[needed] < j){
                        int z = valueToIndx[needed];
                        dp[i][j] = dp[j][z] + 1;
                        ans= max(ans,dp[i][j]);
                    }
                }
            }
            return ans > 2 ? ans : 0;
        }
    };
    