// TC = O(N*logN + N^2)
// MC = O(N) where N is the size of people array
// https://youtu.be/khddrw6Bfyw
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];
        return a[0] < b[0];
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        int len = people.size();
        vector<vector<int> > reconstruct(len, vector<int>(2, -1));

        for(int i = 0; i < len; i++){
            int count = people[i][1];
            for(int j = 0; j < len; j++){
                if(reconstruct[j][0] == -1 && count == 0){
                    reconstruct[j][0] = people[i][0];
                    reconstruct[j][1] = people[i][1];
                    break;
                }
                else if((count != 0 && reconstruct[j][0] >= people[i][0]) || reconstruct[j][0] == -1){
                    count--;
                }
            }
        }
        return reconstruct;
    }
};

/**************************************/
// TC = O(N*logN + N^2)
// MC = O(N) where N is the size of people array
// https://youtu.be/40H5vRK_H2E
class Solution {
public:
    static bool cmp(vector<int> a, vector<int> b){
        if(a[0] == b[0]) return a[1] < b[1];// if height same than sort by asc 'k'
        return a[0] > b[0];// sort by desc height
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);
        int len = people.size();
        vector<vector<int> > reconstruct;
        reconstruct.push_back(people[0]);

        for(int i = 1; i < len; i++){
            int index = people[i][1];
            reconstruct.insert(reconstruct.begin() + index, people[i]);// pos, val..O(N)
        }
        return reconstruct;
    }
};
