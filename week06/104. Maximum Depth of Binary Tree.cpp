// TC = O(N) where N is the total no of nodes in the tree
// MC = O(1)
class Solution {
public:
    void preorder(TreeNode* root, int &depth, int &maxDepth){
        if(!root) return;
        depth++;
        preorder(root->left, depth, maxDepth);
        preorder(root->right, depth, maxDepth);
        maxDepth = max(maxDepth, depth);
        depth--;
    }
    int maxDepth(TreeNode* root) {
        int depth = 0, maxDepth = 0;// input = [], output = 0
        preorder(root, depth, maxDepth);
        return maxDepth;
    }
};

/************************************/
// TC = O(N) where N is the total no of nodes in the tree
// MC = O(1)
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        int leftSubtree = maxDepth(root->left);// left subtree er depth highest koto
        int rightSubtree = maxDepth(root->right);// right subtree er depth highest koto
        return 1 + max(leftSubtree, rightSubtree);// left & right subtree er moddhe jar depth besi seta nibo and root level er jnno +1 krbo
    }
};
