// TC = O(N)
// MC = o(1)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int initial = 0;// 0 ^ A = A, 1 ^ A = A'
        for(auto &num : nums){
            initial = initial ^ num;
        }
        return initial;
    }
};
/********************************/
// TC = O(N)
// MC = o(N)
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq;
        for(auto &num: nums){
            freq[num]++;
        }
        for(auto group:freq){
            if(group.second == 1){
                return group.first;
            }
        }
        return -1;
    }
};
