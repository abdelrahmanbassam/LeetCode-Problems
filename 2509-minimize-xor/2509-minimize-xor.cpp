class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int bits1 = __builtin_popcount(num1);
        int bits2 = __builtin_popcount(num2);
        int diff = abs(bits1 - bits2);

        int ans = num1;
        for(int i = 0; i < 32 && diff ;i++){
            if(bits2 > bits1){
                if(!(num1 & (1 << i))){
                    diff--;
                    ans = ans | (1 << i);
                }
            }
            else{
                 if(num1 & (1 << i)){
                    diff--;
                    ans &= ~(1 << i);  
                }
            }
        }
        
        
        return ans;
    }
};