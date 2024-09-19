class Solution {
public:
int operation(int a,int b,char op)
{
  if(op=='*')
  return a*b;
  if(op=='/')
  return a/b;
  if(op=='+')
  return a+b;
  if(op=='-')
  return a-b;
  return 0;
}
    vector<int> diffWaysToCompute(string ex)
{
   vector<int>allres;
   for( int i=0;i<ex.size();i++)
     {
      char c=ex[i];
      if(c=='+'||c=='-'||c=='*')
      {
        vector<int>resleft=diffWaysToCompute(ex.substr(0,i));//send left string 
        vector<int>resright=diffWaysToCompute(ex.substr(i+1));//send right string 
         for(auto x :resleft )
            for(auto y : resright)
             allres.push_back(operation(x,y,c));
      }
     } 
      if(allres.size()==0)
        allres.push_back(stoi(ex));
        return allres;
}
};