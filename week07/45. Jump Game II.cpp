// TC = O(N) where N is the size of the array
// MC = O(1)
class Solution {
public:
    int jump(vector<int>& nums) {
        int L = 0, R = 0;
        int jumps = 0;
        while(R < nums.size() - 1){
            int mx = 0;
            // max koto "index" porjnto jump korte parbe
            for(int i = L; i <= R; i++){
                mx = max(mx, i + nums[i]);
            }
            L = R + 1;
            R = mx;
            jumps++;
        }
        return jumps;
    }
};

/*******************************/
// TC = O(N * M) where M is max value of nums[pos] and N is the size of the nums array
// MC = O(N)
class Solution {
public:
    int minJump(vector<int> &nums, int pos, vector<int> &dp){
        if(pos >= nums.size() - 1){
            return 0;
        }
        if(nums[pos] == 0) return INT_MAX / 2;
        int &ret = dp[pos];
        if(ret != -1) return ret;
        int ans = INT_MAX / 2;
        for(int i = 1; i <= nums[pos]; i++){
            ans = min(ans, 1 + minJump(nums, pos + i, dp));
        }
        return ret = ans;
    }
    int jump(vector<int>& nums) {
        int pos = 0, n = nums.size();
        vector<int> dp;
        dp.resize(n, -1);
        return minJump(nums, pos, dp);
    }
};