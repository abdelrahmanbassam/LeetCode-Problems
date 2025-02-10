class Solution {
public:
    string clearDigits(string s) {
        string answer;
        for(auto c : s){
            if (isdigit(c) && !answer.empty()) 
                answer.pop_back();
            else
                answer += c;    
        }
        return answer;
    }
};