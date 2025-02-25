class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        int ans = 0,n = arr.size();
        vector<vector<int>> sums(n+1,vector<int> (2,0));//0 for even , 1 for odd
        const int MOD = 1e9 + 7;
        for(int i = 0 ; i < n; i++ ){
            if(arr[i]%2){
                sums[i+1][1] = sums[i][0] + 1;
                sums[i+1][0] = sums[i][1];     
            }
            else{
                sums[i+1][0] = sums[i][0] + 1;
                sums[i+1][1] = sums[i][1];
            }
        }
        for(int i = 1 ; i <= n ;i++){
            ans+=sums[i][1];
            ans %= MOD;
        }
        return ans;

    }
};