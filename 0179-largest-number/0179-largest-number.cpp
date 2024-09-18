class Solution {
public:
    static bool myComp(string s,string h){
        return s + h > h + s;
    }
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        string ans;
        for (auto n : nums) 
            strs.push_back(to_string(n));

        sort(strs.begin(),strs.end(),myComp);
        if (strs[0] == "0") 
            return "0";

        for (auto s : strs) 
            ans += s;
      
        return ans;
    }
};