class Solution {
public:
    bool isSubsequence(string s, string t) {
        int l1 = 0 ,l2 = 0;
        while(l1 < s.size() && l2 < t.size()){
            if(l2 < t.size() && t[l2] != s[l1])
                l2++;
            else{
                l1++;
                l2++;
            }
        }
        return l1 == s.size();
    }
};