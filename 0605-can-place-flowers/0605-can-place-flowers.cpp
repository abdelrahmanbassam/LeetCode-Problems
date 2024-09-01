
class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int sz = flowerbed.size();
        for(int i = 0 ;i < sz ; i++){
            if(flowerbed[i] == 1)
                continue;
            
            bool zLeft = (i == 0 || flowerbed[i-1] == 0);
            bool zRight = (i == sz-1 || flowerbed[i+1] == 0);
            if(zLeft && zRight){
                n--;
                flowerbed[i] = 1;
            }
        }
        return n <= 0;
    }
};
