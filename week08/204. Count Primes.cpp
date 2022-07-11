// TC = O(Nlog(logN))
// MC = O(2*N) where N is the max value of the range
class Solution {
public:
    int countPrimes(int n) {
        if(n <= 2) return 0;
        vector<bool> composite(n + 5, false);
        vector<int> primes;
        composite[0] = true;
        composite[1] = true;

        for(int i = 2; i * i <= n; i++){
            if(composite[i] == false){
                for(int j = i * i; j <= n; j += i){
                    composite[j] = true;
                }
            }
        }
        primes.push_back(2);
        for(int i = 3; i < n; i += 2){
            if(composite[i] == false) primes.push_back(i);
        }
        return primes.size();
    }
};
