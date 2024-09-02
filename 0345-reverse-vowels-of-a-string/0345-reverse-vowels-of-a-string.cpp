class Solution {
public:
    string reverseVowels(string s) {
        string vols = "";
        for(auto &c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                vols += c;
            }
        }   
        reverse(vols.begin(),vols.end()); 
        int j = 0;
        for(auto &c : s){
            if(c=='a' || c=='e' || c=='i' || c=='o' || c=='u' || c=='A' || c=='E' || c=='I' || c=='O' || c=='U'){
                c = vols[j++];
            }
        }
        return s;
    }
};