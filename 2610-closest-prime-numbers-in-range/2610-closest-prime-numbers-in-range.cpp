class Solution {
public:
    vector<int> sievePrimes(int n){
        vector<int> isPrime(n+1,1);
        isPrime[0] = 0;
        isPrime[1] = 0;
        for(int i = 2; i * i <= n; i++){
            for(int j = i*i; j <= n && isPrime[i]; j+=i){
                isPrime[j] = 0;
            }
        }
        return isPrime;
    }
    vector<int> closestPrimes(int left, int right) {
        vector<int> isPrime = sievePrimes(right);
        vector<int> primeNumbers;  
        for (int num = left; num <= right; num++) {
            if (isPrime[num] == 1) {
                primeNumbers.push_back(num);
            }
        }
 
        int mnDis = INT_MAX;
        vector<int> closestPair(2, -1); 
        for(int i = 1; i < primeNumbers.size(); i++){
            int d = primeNumbers[i] - primeNumbers[i-1];
            if(mnDis > d){
                closestPair[0] = primeNumbers[i-1];
                closestPair[1] = primeNumbers[i];
                mnDis = d;
            }
        }
        return closestPair;
    }
};