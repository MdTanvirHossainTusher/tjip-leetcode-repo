// TC = O(logN)
// MC = O(1)
class Solution {
public:
    int firstBadVersion(int n) {
        int L = 0, R = n;
        while(L < R){
            int M = L + (R - L) / 2;
            if(isBadVersion(M)){
                R = M;
            }
            else{
                L = M + 1;
            }
        }
//        return R;// both are correct
        return L;
    }
};
/*************************/
class Solution {
public:
    bool isGoodVersion(int &M){
        return !isBadVersion(M);
    }
    int firstBadVersion(int n) {
        int L = 1, R = n;
        while(L < R){
            int M = L + (R - L + 1) / 2;
            if(isGoodVersion(M)){
                L = M;
            }
            else{
                R = M - 1;
            }
        }
//        return isBadVersion(1)? true : L + 1;// both are correct
        return isBadVersion(1)? true : R + 1;
    }
};
