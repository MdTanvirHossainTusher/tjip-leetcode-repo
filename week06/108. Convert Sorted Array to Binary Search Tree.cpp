// TC = O(N) where N is the size of array
// MC = O(1)
class Solution {
public:
    TreeNode* constructBST(vector<int> &nums, int L, int R){
        if(L > R) return NULL;
        int mid = L + (R - L) / 2;
        TreeNode* curr = new TreeNode(nums[mid]);
        curr->left = constructBST(nums, L, mid - 1);
        curr->right = constructBST(nums, mid + 1, R);
        return curr;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return constructBST(nums, 0, nums.size()-1);
    }
};
