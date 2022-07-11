// TC = O(N) where N is the total no of nodes in the Binary Tree
// MC = O(1)
class Solution {
public:
    int calculatePathSum(TreeNode* &root, int &maxAll){
        if(!root) return 0;
        int left = max(0, calculatePathSum(root->left, maxAll));
        int right = max(0, calculatePathSum(root->right, maxAll)); // '0' to avoid negative values
        maxAll = max(maxAll, left + right + root->val);// boro val save kore rkhchi
        return root->val + max(left, right);// but jekono ek side(left, right) ke return krchi
    }
    int maxPathSum(TreeNode* root) {
        int maxAll = INT_MIN/2;
        calculatePathSum(root, maxAll);
        return maxAll;
    }
};
