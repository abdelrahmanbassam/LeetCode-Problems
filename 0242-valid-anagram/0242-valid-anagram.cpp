class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int> oc1(26,0),oc2(26,0);
        for(auto c : s)
            oc1[c-'a']++;
        
        for(auto c : t)
            oc2[c-'a']++;
        
        return oc1 == oc2;
    }
};