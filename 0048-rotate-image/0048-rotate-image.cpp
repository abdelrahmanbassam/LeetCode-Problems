class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int l = 0 , r = n - 1;
        while(l < r){
            for(int i = 0; i < r - l ; i++){
                int top = l , down = r;
                int topLeft = matrix[top][l + i];
                matrix[top][l + i] = matrix[down - i][l];
                matrix[down - i][l] = matrix[down][r - i];
                matrix[down][r - i] = matrix[top + i][r];
                matrix[top + i][r] = topLeft;
            }
            r--;
            l++;
        } 
    }
};