// TC = O(N) where N = total no of nodes/ids
// MC = O(2*N)
class Solution {
public:
    void totalImportance(int u, unordered_map<int, vector<int> > &sub, int &ans, unordered_map<int, int> &imp){

        ans += imp[u];
        for(auto v : sub[u]){
            totalImportance(v, sub, ans, imp);
        }
        return;
    }

    int getImportance(vector<Employee*> employees, int id) {
        int n = employees.size();
        unordered_map<int, vector<int> > sub;
        unordered_map<int, int> imp;

        for(int i = 0; i < n; i++){
            imp[employees[i]->id] = employees[i]->importance;
            for(auto s: employees[i]->subordinates){
                sub[employees[i]->id].push_back(s);
            }
        }
        int ans = 0;
        totalImportance(id, sub, ans, imp);
        return ans;
    }
};
