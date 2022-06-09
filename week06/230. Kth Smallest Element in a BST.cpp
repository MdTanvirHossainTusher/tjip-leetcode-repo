// TC = O(N) where N is no of elements in the tree
// MC = O(1)
class Solution {
public:
    void runInorder(TreeNode* &root,int &k, int &kthValue){
        if(!root) return;
        runInorder(root->left, k, kthValue);
        k--;
        if(k == 0){
            kthValue = root->val;
            return;
        }
        runInorder(root->right, k, kthValue);
    }
    int kthSmallest(TreeNode* root, int k) {
        int kthValue;
        runInorder(root, k, kthValue);
        return kthValue;
    }
};

/****************************************/
// TC = O(N) where N is no of elements in the tree
// MC = O(1)
class Solution {
public:
    int runInorder(TreeNode* &root,int &k){
        if(!root) return -1;
        int L = runInorder(root->left, k);
        k--;
        if(k == 0){
            return root->val;
        }
        int R = runInorder(root->right, k);
        return max(L, R);
    }
    int kthSmallest(TreeNode* root, int k) {
        return runInorder(root, k);
    }
};
