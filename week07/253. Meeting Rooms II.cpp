// TC = O(N) where N is the no of intervals
// MC = O(2*N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        map<int, int> status;
        for(auto interval: intervals){
            status[interval[0]]++;
            status[interval[1]]--;
        }
        int rooms = 0;
        int minRoomReq = 1;
        for(auto stat: status){
            rooms += stat.second;
            minRoomReq = max(minRoomReq, rooms);
        }
        return minRoomReq;
    }
};

/*********************************/
// TC = O(N) where N = 1000010
// MC = O(N)
class Solution {
public:
    int minMeetingRooms(vector<vector<int>>& intervals) {
        vector<int> status(1000010, 0);
        for(auto interval : intervals){
            status[interval[0]]++;
            status[interval[1]]--;
        }
        for(int i = 1; i < 1000010; i++){
            status[i] += status[i - 1];
        }
        return *max_element(status.begin(), status.end());
    }
};

