class Solution {
public:
    int nthUglyNumber(int n) {
        set<long> ugly;
        ugly.insert(1);
        long smallestUgly;
        for(int i = 1 ; i < n ; i++){
            smallestUgly = *ugly.begin();
            ugly.erase(ugly.begin());
            ugly.insert(smallestUgly * 2);
            ugly.insert(smallestUgly * 3);
            ugly.insert(smallestUgly * 5);
        }
        return *ugly.begin();
    }
};