class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> ans;
        int carry = 1;
        for(int i = digits.size() - 1; i >= 0; i--){
            if(carry){
                digits[i] += carry;
                carry = 0;
            }
            if(digits[i] > 9){
                ans.push_back(0);
                carry = 1;
            }
            else
                ans.push_back(digits[i]);
        }
        if(carry)
           ans.push_back(carry);
        reverse(ans.begin(),ans.end());
        return ans;

    }
};