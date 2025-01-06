class Solution {
public:
    vector<int> minOperations(string boxes) {
        vector<int> ans(boxes.length()); 
        int operations = 0,cnt = 0;
        
    for (int i = 0 ; i < boxes.length(); ++i) {
       ans[i] += operations;
       cnt += boxes[i] == '1';
       operations += cnt;
    }
    operations = 0,cnt = 0;
    for (int i = boxes.length() - 1; i >= 0; --i) {
        ans[i] += operations;
        cnt += boxes[i] == '1' ;
        operations += cnt;
    }
    return ans;
    }
};