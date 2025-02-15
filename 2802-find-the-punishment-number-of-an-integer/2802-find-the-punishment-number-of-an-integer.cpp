class Solution {
public:
    bool partitionable(int num, int goal){
        if(goal == num)
            return true;
        if(num < goal || goal < 0)
            return false;
        return  partitionable(num / 10, goal - num % 10) ||
                partitionable(num / 100, goal - num % 100) ||
                partitionable(num / 1000, goal - num % 1000);
    } 
    int punishmentNumber(int n) {
        int ans = 0;
        for(int i = 1; i <= n; i++){
            if(partitionable(i*i,i))
                ans += i*i;
        }
        return ans;
    }
};