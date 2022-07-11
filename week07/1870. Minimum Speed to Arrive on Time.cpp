// TC = O(N*logN) where N is the size of the dist array
// MC = O(1)
class Solution {
public:
    double passedTime(int &M, vector<int> &dist, double &hour){
        double times = 0;
        int i;
        for(i = 0; i < dist.size() - 1; i++){
            times += ceil((dist[i] * 1.0) / M);
        }
        times += (dist[i] * 1.0) / M;
        return times;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int L = 1, R = 1000000000;
        while(L < R){
            int M = L + (R - L) / 2;
            double timeReq = passedTime(M, dist, hour);

            if(timeReq <= hour){
                R = M;
            }
            else{
                L = M + 1;
            }
        }
        return R == 1000000000 ? -1 : L;
    }
};

/**********************************/
// TC = O(N*logN) where N is the size of the dist array
// MC = O(1)
class Solution {
public:
    double passedTime(double &M, vector<int> &dist, double &hour){
        double times = 0;
        int i;
        for(i = 0; i < dist.size() - 1; i++){
            times += ceil((dist[i]) / M);
        }
        times += (dist[i] * 1.0) / M;
        cout<<times<<endl;
        return times;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int L = 1, R = 1000000000, ans = -1;
        while(L <= R){
            double M = L + (R - L) / 2;
            double timeReq = passedTime(M, dist, hour);

            if(timeReq <= hour){
                ans = M;
                R = M - 1;
            }
            else{
                L = M + 1;
            }
        }
        return ans;
    }
};
