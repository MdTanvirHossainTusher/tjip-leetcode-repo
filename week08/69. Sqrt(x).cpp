// TC = O(logN) where N = x
// MC = O(1)
class Solution {
public:
    int mySqrt(int x) {
        long long L = 0, R = x;
        while(L < R){
            long long M = L + (R - L + 1) / 2;
            if(M * M > x){
                R = M - 1;
            }
            else{
                L = M;
            }
        }
        return R;
    }
};
/***************************/
// TC = < O(logN) where N = x
// MC = O(1)
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        double xN = x, prv = 0;
        while(fabs(xN - prv) >= 1e-6){
            prv = xN;
            xN = ((xN * xN) + x) / (xN + xN);
        }
        return xN;
    }
};
/***************************/
// TC = < O(logN) where N = x
// MC = O(1)
class Solution {
public:
    int mySqrt(int x) {
        if(x == 0) return 0;
        double xN = x, prv;
        int cnt = 20;
        while(1){
            prv = xN;
            xN = ((xN * xN) + x) / (xN + xN);
            if(fabs(xN - prv) <= 1e-6) break;
        }
        return xN;
    }
};
