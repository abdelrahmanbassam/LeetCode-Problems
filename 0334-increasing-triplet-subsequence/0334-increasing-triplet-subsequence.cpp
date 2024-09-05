class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {
        int e1 = INT_MAX,e2 = INT_MAX;
        //just make sure that e1 is less than e2 
        //and there is a number larger than both
        for(auto &e : nums){
            if(e <= e1)
                e1 = e;
            else if(e <= e2)
                e2 = e;
            else 
                return true;
        }
        //e1 and e2 not 100% are the numbers but the order of taking the if condition makes sure that there is a number less than e2 and behind
        return false;
    }
};