#include <vector>
using namespace std;

class Solution {
public:
    vector<int> dp;

    Solution() : dp(38, -1) {}  // Initialize dp with size 38 and all values set to -1

    int tribonacci(int n) {
        if (n == 0) 
            return 0;
        if (n == 1 || n == 2) 
            return 1;
        if (dp[n] != -1)
            return dp[n];

        return dp[n] = tribonacci(n - 1) + tribonacci(n - 2) + tribonacci(n - 3);
    }
};
