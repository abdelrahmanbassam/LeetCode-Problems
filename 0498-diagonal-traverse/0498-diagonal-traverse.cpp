class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> ans;
        bool right = true;
        int n = mat.size(), m = mat[0].size();
        int curX = 0 ,curY = 0;

        while(curX < n && curY < m){
            ans.push_back(mat[curX][curY]);
            if(right){
                while(curX > 0 && curY + 1< m){
                    curX--;
                    curY++; 
                    ans.push_back(mat[curX][curY]);
                }
                if (curY == m - 1)
                    curX++;
                else
                    curY++;
            }
            else{
                while(curX + 1 < n && curY > 0){
                    curX++;
                    curY--; 
                    ans.push_back(mat[curX][curY]);
                }
                if (curX == n - 1)
                    curY++;
                else
                    curX++;
            }
            right = !right;
        }
        return ans;
    }
};