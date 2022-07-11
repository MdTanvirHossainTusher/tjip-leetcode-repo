// TC = O(NlogN)
// MC = O(N) where N is the size of the points array
class Solution {
public:
    double getAngle(double dy, double dx){
        double rad = atan2(dy, dx);
        double deg = (180 * rad) / acos(-1.0);
        return deg < 0 ? deg + 360 : deg;
    }

    int visiblePoints(vector<vector<int>>& points, int angle, vector<int>& location) {
        vector<double> angles;
        int duplicate = 0;

        for(auto &point : points){
            if(point == location) duplicate++;
            else{
                angles.push_back(getAngle(point[1] - location[1], point[0] - location[0]));
            }
        }
        sort(angles.begin(), angles.end());
        int maxPoint = 0;
        int upper = 0, n = angles.size();

        for(int lower = 0; lower < n; lower++){
            while((upper < n && angles[upper] - angles[lower] <= angle) ||
                 (upper >= n && 360 + angles[upper % n] - angles[lower] <= angle)){
                upper++;
            }
            maxPoint = max(maxPoint, upper - lower);
        }
        return maxPoint + duplicate;
    }
};
