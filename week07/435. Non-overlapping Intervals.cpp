// TC = O(N*logN) where N is the size of the intervals array
// MC = O(logN)
// https://youtu.be/BTObFnHbD4U
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        int left = 0, right = 1, count = 0, n = intervals.size();
        while(right < n){
            if(intervals[left][1] <= intervals[right][0]){
                left = right, right++;
            }
            else if(intervals[right][1] > intervals[left][1]){
                right++;
                count++;
            }
            else if(intervals[left][1] >= intervals[right][1]){
                left = right;
                right++;
                count++;
            }
        }
        return count;
    }
};
