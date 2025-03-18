class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();
        vector<pair<int, int>> pair;
        for (int i = 0; i < n; i++) {
            pair.push_back({position[i], speed[i]});
        }
        sort(pair.rbegin(), pair.rend());       
        int fleets = n;
        double timeToTarget = (target - pair[0].first) / (1.0 * pair[0].second) ;

        for(int i = 1; i < n; i++){
            double curCarTime = (target - pair[i].first) / (1.0 * pair[i].second);
            if(curCarTime <= timeToTarget){
                fleets--;
            }
            else{
                timeToTarget = curCarTime;
            }
        }
        return fleets;
    }
};