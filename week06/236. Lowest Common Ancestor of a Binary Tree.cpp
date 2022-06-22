// TC = O(N) where N is the total no of nodes in the tree
// MC = O(1)
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(!root) return NULL;
        if(root->val == p->val || root->val == q->val) return root;
        TreeNode* L = lowestCommonAncestor(root->left, p, q);// left subtree te srch for p,q
        TreeNode* R = lowestCommonAncestor(root->right, p, q);// right subtree te srch for p,q
        if(L && R) return root;
        return L?L:R;
    }
};
