class Solution {
public:
    bool checkPowersOfThree(int n) {
        int curPower3 = 0;
        while(pow(3,curPower3) <= n){
            curPower3++;
        }

        while(n > 0 && curPower3 >= 0){
            if(n >= pow(3,curPower3))
                n -= pow(3,curPower3);
            curPower3--;
        }
        return n == 0;
    }
};