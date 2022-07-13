// TC = O(N) where N = total no of nodes
// M = O(N) recursion call total N times for N nodes
class Solution {
public:
    int findMinTime(int u, vector<vector<int> > &boss, vector<int> &informTime){
        int maxTime = 0;
        for(auto v: boss[u]){
            maxTime = max(maxTime, findMinTime(v, boss, informTime));
        }
        return maxTime + informTime[u];
    }
    int numOfMinutes(int n, int headID, vector<int>& parent, vector<int>& informTime) {
        vector<vector<int> > boss(n + 1);
        for(int i = 0; i < n; i++){
            if(parent[i] != -1)
                boss[parent[i]].push_back(i);
        }
        return findMinTime(headID, boss, informTime);
    }
};
