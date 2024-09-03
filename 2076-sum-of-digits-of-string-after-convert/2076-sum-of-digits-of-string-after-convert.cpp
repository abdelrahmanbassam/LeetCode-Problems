class Solution {
public:
    int getLucky(string s, int k) {
        int num = 0;
        for(auto &c : s){
            int curVal = c - 'a' + 1;
            while(curVal){
                num+=curVal%10;
                curVal /=10;;
            }
        } 
        for(int i = 0; i < k-1; i++){
            int newNum = 0;
            while(num){
                newNum+=num%10;
                num /=10;;
            }
            num = newNum;
        }
        return  num;
    }
};