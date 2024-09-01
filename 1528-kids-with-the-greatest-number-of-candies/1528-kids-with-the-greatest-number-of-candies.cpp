class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int mx = *max_element(candies.begin(),candies.end());
        vector<bool>canBeMax(candies.size());
        for(int i = 0; i < candies.size() ; i++)
            canBeMax[i] = (candies[i]+extraCandies) >= mx;
        return canBeMax;
    }

};