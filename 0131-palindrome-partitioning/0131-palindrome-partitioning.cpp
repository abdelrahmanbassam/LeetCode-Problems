class Solution {
public:
    bool isPalindrome(string &s){
        int n = s.size();
        for(int i = 0; i < n/2 ;i++){
            if(s[i] != s[n-i-1])
                return false;
        }
        return true;
    }

    vector<vector<string>> partitionHelper(string &s,int i){
        if(i == s.size()){
            return {{}};
        }
        vector<vector<string>> allPartisions;

        for(int j = i; j < s.size(); j++){
            string leftPart = s.substr(i,j - i + 1);

            if(isPalindrome(leftPart)){
                vector<vector<string>> validParts = partitionHelper(s,j+1);

                for(auto &v : validParts){
                    v.insert(v.begin(),leftPart);
                    allPartisions.push_back(v);
                }

            }
        }
        return allPartisions;
    }
    vector<vector<string>> partition(string s) {
        return partitionHelper(s,0);
    }
};