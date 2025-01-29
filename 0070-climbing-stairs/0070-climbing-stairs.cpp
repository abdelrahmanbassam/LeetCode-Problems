class Solution {
public:
    int climbStairs(int n) {
        if(n <= 2)
            return n;
        int f = 1, s = 2,temp;
        for(int i = 3; i <= n; i++){
            temp = s;
            s += f;
            f = temp;
        } 
        return s;
    }
};