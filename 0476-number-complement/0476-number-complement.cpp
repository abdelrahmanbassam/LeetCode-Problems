class Solution {
public:
    int findComplement(int num) {
        int ans = 0;
        for(int i = 0; num; i++){
           ans += (num & 1) ? 0 :  1 << i;
           num = num >> 1;
        }
        return ans;
    }
};