class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();
        int l = 0, r = m * n - 1;
        while(l <= r){
            int mid = (l+r)/2;
            int x = mid / m;
            int y = mid % m;
            cout<< x << " "<< y<<endl;
            if(matrix[x][y] == target)
                return true;
            if(matrix[x][y] > target)
                r = mid - 1;
            else
                l = mid + 1;

        }
        return false;

    }
};