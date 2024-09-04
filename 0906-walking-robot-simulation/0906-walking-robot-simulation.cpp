class Solution {
public:
    int robotSim(vector<int>& commands, vector<vector<int>>& obstacles) {
        // up, right, down,left
        vector<pair<int, int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        map<pair<int,int>,bool> obs;
        pair<int, int> curPoint = {0,0};
        int ans = 0;
        for(auto &v : obstacles){
            obs[{v[0],v[1]}] = true;
        }
        int curDir = 0;
        for(auto &c :commands){
            if(c == -1)
                curDir = (curDir + 1) %4;
            else if(c == -2)
                curDir = (curDir + 3) %4;
            else{
                while(c--){
                    int nX =  curPoint.first + dir[curDir].first ;
                    int nY =  curPoint.second + dir[curDir].second ;
                    if(obs.find({nX,nY}) != obs.end())
                        break;
                    ans = max(ans,nX * nX + nY * nY);
                    curPoint = {nX,nY};
                }
            }
        }
        return ans; 
    }
};