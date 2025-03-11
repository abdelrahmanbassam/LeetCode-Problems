class Solution {
public:
    double myPow(double x, int n) {
      long double ans = 1,cur = x;
      for(long i = abs((long)n); i > 0 ; i/=2)
      {
        if(i%2)
         ans = ans*cur;
        
        cur*=cur;   
      }
      

      if(n<0)
       ans = 1/ans;

      return ans; 
    }
};