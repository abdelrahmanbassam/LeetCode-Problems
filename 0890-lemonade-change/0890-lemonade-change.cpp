class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        vector<int> change(3,0);
        for(int i = 0 ; i <bills.size() ; i++ ){
            if(bills[i] == 5)
                change[0]++;
            else if(bills[i] == 10){
                if(change[0] == 0)
                    return false;
                change[0]--;
                change[1]++;
            }
            else{
                if(change[1] > 0 && change[0] > 0){
                    change[1]--;
                    change[0]--;
                }
                else if(change[0] >= 3)
                    change[0] -= 3;
                else
                    return false;
            }
            
        }  
        return true;   
    }
};