// TC = O(N*logN) where N is the size of the array
// MC = O(N)
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> overwrite;
        overwrite.push_back(nums[0]);
        for(int i = 1; i < n; i++){
            if(nums[i] > overwrite.back()){
                overwrite.push_back(nums[i]);
            }
            else{
                int idx = lower_bound(overwrite.begin(), overwrite.end(), nums[i]) - overwrite.begin();
                //cout<<idx<<" --\n";
                overwrite[idx] = nums[i];
            }
        }
        return overwrite.size();
    }
};

/****************************************/
// TC = O(N^2) where N is the size of the array
// MC = O(N*N), cache size = N & 2nd N for auxilary space
class Solution {
public:
    vector<int> cache;
    int calculateLIS(int pos, vector<int> &nums){
        if(pos >= nums.size()){// last a ase prsi tar mane eikhn theke kno LIS pai na..tai 0
            return 0;
        }
        if(cache[pos] != -1) return cache[pos];
        int lis = 1; // included nums[pos]..tai lis = 1
        for(int i = pos + 1; i < nums.size(); i++){
            if(nums[pos] < nums[i]){
                lis = max(lis, 1 + calculateLIS(i, nums));// +1 krsi cz nums[pos] ke nibo..fole LIS er length 1 barbe
            }
        }
        return cache[pos] = lis;
    }
    int lengthOfLIS(vector<int>& nums) {
        cache.clear();
        int n = nums.size();
        cache.resize(n, -1);
        int maxLen = 1;
        // calculateLIS(i, nums) means nums[pos] ke include kore, [pos + 1, n - 1] ei range
        // e LIS er length
        for(int i = 0; i < n; i++){
            maxLen = max(maxLen, calculateLIS(i, nums));
        }
        return maxLen;
    }
};

/****************************************/
// TC = O(N^2) where N is the size of the array
// MC = O(N)
class Solution {
public:
    vector<int> cache;
    int findLengthOfLIS(int n, vector<int> &nums){
        int maxLen = 1;
        for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
                if(nums[i] < nums[j]){
                    cache[i] = max(cache[i], cache[j] + 1);
                    maxLen = max(maxLen, cache[i]);
                }
            }
        }
        return maxLen;
    }
    int lengthOfLIS(vector<int>& nums) {
        cache.clear();
        int n = nums.size();
        cache.resize(n, 1);
        return findLengthOfLIS(n, nums);
    }
};
