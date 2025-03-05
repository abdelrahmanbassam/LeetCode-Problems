class Solution {
public:
    long long coloredCells(int n) {
        long long numCells = 0;
        int iter = n - 1;
        int add = 1;
        while(iter--){
            numCells += 2*add;
            add+=2;
        }
        numCells += add;
        return numCells;
    }
};