class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        int n = grid.size(),m = grid[0].size();
        vector<int> vc;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                vc.push_back(grid[i][j]);
            }
        }
        sort(vc.begin(),vc.end());
        int median = vc[(n*m)/2],ans = 0;
        cout << median<<endl;
        for(int i = 0; i < n*m; i++){
            if(vc[i] == median)
                continue;
            cout<< abs(median - vc[i])<<" ";
            int times = (abs(median - vc[i]) + x - 1) / x;
            cout<< times << endl;
            ans +=times;
            if(vc[i] < median){
                vc[i] += x*times;
            }
            else if(vc[i] > median){
                vc[i] -= x*times;
            }
            if(vc[i] != median)
                return -1;
        }
        return ans;
    }
};