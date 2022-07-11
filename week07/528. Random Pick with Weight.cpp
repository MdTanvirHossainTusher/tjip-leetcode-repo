// TC = O(N)
// MC = O(N) where N is the size of the weight array
mt19937 rd(0);
class Solution {
public:
    vector<int> prefixSum;
    Solution(vector<int>& w) {
        // prefixSum = w;
        prefixSum.push_back(w[0]);
        for(int i = 1; i < w.size(); i++){
            // prefixSum[i] = prefixSum[i - 1] + w[i];
            prefixSum.push_back(prefixSum[i - 1] + w[i]) ;
        }
    }
    int getRandomInRange(int L, int R){
        return L + (rd() % (R - L + 1));
    }
    int pickIndex() {
        int totalSum = prefixSum.back();
        int rnv = getRandomInRange(1, totalSum); // prefixSum = [1,17] er moddhe 11 khujbo ja value
        return lower_bound(prefixSum.begin(), prefixSum.end(), rnv) - prefixSum.begin();
    }
};
