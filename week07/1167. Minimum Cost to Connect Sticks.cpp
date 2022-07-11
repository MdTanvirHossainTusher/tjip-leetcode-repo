// TC = O(N*logN)..each insert operation O(logN).. N insert operation takes O(NlogN)
// MC = O(N) where N is the number of sticks
class Solution {
public:
    int connectSticks(vector<int>& sticks) {
        priority_queue<int, vector<int>, greater<int> > stickLength(sticks.begin(), sticks.end());
        int minCost = 0;
        while(stickLength.size() != 1){
            int minValue1 = stickLength.top();
            stickLength.pop();
            int minValue2 = stickLength.top();
            stickLength.pop();
            stickLength.push(minValue1 + minValue2);
            minCost += (minValue1 + minValue2);
        }
        return minCost;
    }
};
