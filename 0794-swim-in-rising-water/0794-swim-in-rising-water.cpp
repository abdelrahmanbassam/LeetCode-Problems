class Solution {
public:
    int dirX[4] = {1,-1,0,0};
    int dirY[4] = {0,0,-1,1};

    int swimInWater(vector<vector<int>>& grid) {
        
        priority_queue < pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>, 
                        greater<pair<int, pair<int, int>>> 
                        > pq;        

        pq.push({grid[0][0],{0,0}});


        int maxCostInPath = INT_MIN;
        vector<vector<int>> visited = grid;
        visited[0][0] = -1;
        int n = grid.size(),m = grid[0].size();
        while(pq.size()){
            auto [cost,pos] = pq.top();
            // cout<<cost<<" "<<pos.first<<" "<<pos.second<<endl;
            pq.pop();
            maxCostInPath = max(maxCostInPath,cost);
            if (pos.first == n - 1 && pos.second == m - 1){
                // cout<<"reached";
                break;
            }
            for(int d = 0 ; d < 4; d++){
                int newX = pos.first + dirX[d];
                int newY = pos.second + dirY[d];
                if(!(newX >= 0 && newX < n && newY >= 0 && newY < m)){
                    continue;
                }
                if(visited[newX][newY] == -1)
                    continue;

                visited[newX][newY] = -1;
                
                pq.push({grid[newX][newY],{newX,newY}});
            }
        }
        return maxCostInPath;
    }
};