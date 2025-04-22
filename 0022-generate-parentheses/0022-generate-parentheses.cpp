class Solution {
public:
    vector<string> res;
    string curSt = "";
    void backtracking(int openN,int closeN,int &n){
        if(openN == closeN && openN == n){
            res.push_back(curSt);
            return;
        }
        if(openN < n){
            curSt.push_back('(');
            backtracking(openN + 1,closeN,n);
            curSt.pop_back();
        }
        if(closeN < openN){
            curSt.push_back(')');
            backtracking(openN,closeN + 1,n);
            curSt.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        backtracking(0,0,n);
        return res;
    }
};