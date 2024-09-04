class Solution {
public:
    bool closeStrings(string word1, string word2) {
        unordered_map<char,int> oc1,oc2;
        for(auto &c : word1)
            oc1[c]++;
        
        for(auto &c : word2)
            oc2[c]++;

        for(auto &fr1 : oc1){
            if(oc2.find(fr1.first) == oc2.end())
                return false;

            for(auto &fr2 : oc2){
                if(fr1.second == fr2.second){
                    swap(oc2[fr1.first],fr2.second);
                    oc2[fr1.first] = 0 ;
                    fr1.second = 0;
                    break;
                }
            }
           
        }
        for(auto &fr1 : oc1) if(fr1.second !=0) return false;
        for(auto &fr2 : oc2) if(fr2.second !=0) return false;
        return true;

    }
};