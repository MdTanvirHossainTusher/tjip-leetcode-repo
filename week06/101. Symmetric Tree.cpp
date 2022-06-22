// TC = O(N); N is the no of total nodes in the tree
// MC = O(N)
class Solution {
public:
    void preorder(TreeNode* root, vector<int> &pre){
        if(!root){
            pre.push_back(0);
            return;
        }
        pre.push_back(root->val);
        preorder(root->left, pre);
        preorder(root->right, pre);
    }
    void postorder(TreeNode* root, vector<int> &post){
        if(!root){
            post.push_back(0);
            return;
        }
        postorder(root->left, post);
        postorder(root->right, post);
        post.push_back(root->val);
    }
    bool isEqual(vector<int> &pre, vector<int> &post){
        if(pre.size() != post.size()) return false;
        for(int i = 0; i < pre.size(); i++){
            if(pre[i] != post[i]){
                return false;
            }
        }
        return true;
    }
    bool isSymmetric(TreeNode* root) {
        vector<int> pre, post;
        preorder(root->left, pre);
        postorder(root->right, post);
        reverse(post.begin(), post.end());

        if(isEqual(pre, post)) return true;
        return false;
    }
};

/*************************************/
// TC = O(N); N is the no of total nodes in the tree
// MC = O(1)
class Solution {
public:
    bool isSubtreeSym(TreeNode* left, TreeNode* right){
        if(left == NULL || right == NULL){
            return left == right;
        }
        if(left->val != right->val) return false;
        return isSubtreeSym(left->left, right->right) && isSubtreeSym(left->right, right->left);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root) return true;
        return isSubtreeSym(root->left, root->right);
    }
};
