class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int ans = INT_MAX,b = 0;
        for(int i = 0 ;i < k ;i++){
            b += blocks[i] == 'B';
        }
        ans = k - b;
        for(int i = k; i < blocks.size(); i++){
            b -= blocks[i - k] == 'B';
            b += blocks[i] == 'B';
            ans = min(ans,k - b);
        }
        return ans;
    }
};