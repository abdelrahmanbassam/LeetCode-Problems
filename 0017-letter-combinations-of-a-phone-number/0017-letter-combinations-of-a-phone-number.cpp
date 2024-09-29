class Solution {
public:
map<char,string>phone;
vector<string> compinations;
void hamada(string digits,int i,string x)
{
    if(x.size()==digits.size()){
        compinations.push_back(x);
        return;
    }
  for(auto c :phone[digits[i]])
      hamada(digits,i+1,x+c);
}

vector<string> letterCombinations(string digits) {
    phone['2'] = "abc";
    phone['3'] = "def";
    phone['4'] = "ghi";
    phone['5'] = "jkl";
    phone['6'] = "mno";
    phone['7'] = "pqrs";
    phone['8'] = "tuv";
    phone['9'] = "wxyz";
       if(digits.size())
       hamada(digits,0,"");
       return compinations; 
    }
};