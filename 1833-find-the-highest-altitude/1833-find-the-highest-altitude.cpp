class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int curAtt = 0,ans = 0;
        for(int i = 0 ; i < gain.size() ; i++){
            curAtt +=gain[i];
            ans= max(ans,curAtt);
        }
        return  ans;
    }
};