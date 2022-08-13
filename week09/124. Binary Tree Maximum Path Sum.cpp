// TC = O(N)
// MC = O(N) where N is the total no nodes
class Solution {
public:
    int max_path_sum;

    int maxChainSum(TreeNode* u){
        if(!u) return 0;
        int left = maxChainSum(u->left);
        int right = maxChainSum(u->right);
        max_path_sum = max(max_path_sum, u->val + left + right);// max path sum
        return max(0, u->val + max(left, right));// max chain sum
    }
    int maxPathSum(TreeNode* root) {
        max_path_sum = INT_MIN / 2;
        maxChainSum(root);
        return max_path_sum;
    }
};
