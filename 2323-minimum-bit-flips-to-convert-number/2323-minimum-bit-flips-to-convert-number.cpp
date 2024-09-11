class Solution {
public:
    int minBitFlips(int s, int g) {
        int ans = 0;
        while(s != 0 || g !=0){
            if( (s & 1) != (g & 1))
                ans++;
            s = s >>1;
            g = g >>1;
        }    
        return ans;
    }
};