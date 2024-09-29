class Solution {
public:
    int minFlips(int a, int b, int c) {
        int lastBits = 0,lBC = 0,ans = 0;
        for(int i = 0 ; i < 32 ;i++){
            lastBits =  a &1;
            lastBits += b &1;
            lBC = c & 1;
            a = a >> 1; 
            b = b >> 1; 
            c = c >> 1; 
            if(lBC == 0)
                ans += lastBits;
            else
                ans += (lastBits == 0);
        }
        return ans;
    }
};