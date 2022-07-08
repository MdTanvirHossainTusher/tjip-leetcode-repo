// TC = O(log10(N))
// MC = O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int power = 0, prime = 5;

        while(n >= prime){
            power +=  n/prime;
            prime *= 5;
            cout<<power<<" "<<prime<<endl;
        }
        return power;
    }
};
