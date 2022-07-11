// TC = O(logn)
// MC = O(logn) where n is the power
class Solution {
public:
    double modularExpo(double x, long long n){
        if(n == 1) return x * 1.0;
        if(n % 2 == 0){
            double v = modularExpo(x, n / 2);
            return v * v;
        }
        return x * modularExpo(x, n - 1);
    }
    double myPow(double x, int n) {
        bool isNeg = false;

        if(n == 0) return 1;
        if(n == 1) return x;
        // mx = INT_MAX = 2147483647
        // mn = INT_MIN = -2147483648
        // mx + 1 = mn, mn - 1 = mx;
        long long nn = (long long)n;
        if(n < 0){
            isNeg = true;
            nn *= -1.0;
        }
        double res = modularExpo(x, nn);
        if(isNeg) return 1.0 / res;
        else return res;
    }
};
