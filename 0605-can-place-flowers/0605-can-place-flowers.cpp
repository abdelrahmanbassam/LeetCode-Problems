class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        
        for(int i = 0; i < flowerbed.size();i++){
            if(flowerbed[i])
                continue;
            bool left = (i == 0) || (flowerbed[i-1] == 0);
            bool right = (i == flowerbed.size()-1 )  || (flowerbed[i+1] == 0);
            cout<<i<<" "<<left<<" "<<right<<endl;
            n-= (left && right);
            flowerbed[i] = (left && right);
        }
        return n <= 0;
    }
};