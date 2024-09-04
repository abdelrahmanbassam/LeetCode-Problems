class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()) return false;
        vector<int> freq1(26,0),freq2(26,0);
        
        for(auto c:word1) freq1[c-'a']++;
        for(auto c:word2) freq2[c-'a']++;
        
        multiset<int> s1,s2;
        for(int i=0;i<26;i++){
            if((freq1[i]==0 && freq2[i]!=0) || (freq1[i]!=0 && freq2[i]==0)) return false;
            if(freq1[i]!=0){
                s1.insert(freq1[i]);
                s2.insert(freq2[i]);
            }
        }
        return s1==s2;
    
    }
};