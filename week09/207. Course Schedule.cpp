// TC = O(N + E)
// MC = O(2N * N) where N is the total no of nodes
class Solution {
public:
    bool isCycle(int u, vector<bool> &vis, vector<bool> &recStack, vector<vector<int> > &courses){
        vis[u] = true;
        recStack[u] = true;
        for(auto v: courses[u]){
            if(vis[v] == 0){
                if(isCycle(v, vis, recStack, courses)) return true;
            }
            else if(recStack[v]){
                return true;
            }
        }
        recStack[u] = false;
        return false;
    }
    bool detectCycle(int &numCourses, vector<vector<int> > &courses){
        vector<bool> vis(numCourses + 1), recStack(numCourses + 1);
        for(int i = 0; i < numCourses; i++){
            if(vis[i] == 0){
                if(isCycle(i, vis, recStack, courses)){
                    return true;
                }
            }
        }
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int> > courses(numCourses + 1);
        for(auto crs: prerequisites){
            courses[crs[0]].push_back(crs[1]);
        }
        return !detectCycle(numCourses, courses);
    }
};
