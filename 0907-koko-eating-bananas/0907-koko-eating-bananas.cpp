class Solution {
public:
    long long clacHours(vector<int>& piles,int k){
        long long ans = 0 ;
        for(auto pile : piles)
            ans += ((pile + k - 1) / k);
        return ans; 
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        long long l = 1, r=1e9+1,ans = -1 ;
        while(l <= r){
            long long mid = (l+r)/2;
            if(clacHours(piles,mid) <= h){
                ans = mid;
                r = mid - 1;
            }
            else
                l = mid + 1;
        }
        return ans;
    }
};