class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> freq;
        if(hand.size()%groupSize)
            return false;
        for(int i = 0; i < hand.size(); i++){
            freq[hand[i]]++;
        }
        for(auto &e : freq){
            if(e.second == 0)
                continue;
            int num = e.first;
            int curf = e.second;
            for(int i = 0; i < groupSize; i++){
                if(freq[num + i] < curf)
                    return false;
                else
                    freq[num + i] =  freq[num + i] - curf;
            }
        }
        return true;
    }
};