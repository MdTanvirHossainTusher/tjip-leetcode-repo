// O(N); N is the total number of nodes
// O(1)
class Solution {
public:
    bool validBST(TreeNode* root, long long L_mn, long long R_mx){
        if(!root) return true;// tree er last a pouchaise parsi..tar mane mjhe kothao prb nai..tai true hbe
        long long v = root->val;
        if(v < L_mn || v > R_mx) return false;
        return validBST(root->left, L_mn, v-1) && validBST(root->right, v+1, R_mx);
    }
    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
};

/************************************/
// O(N); N is the total number of nodes
// O(1)
class Solution {
public:
    bool validBST(TreeNode* root, long long L_mn, long long R_mx){
        if(!root) return true;// tree er last a pouchaise parsi..tar mane mjhe kothao prb nai..tai true hbe
        long long v = root->val;
        if(v >= R_mx || v <= L_mn) return false;
        return validBST(root->left, L_mn, v) && validBST(root->right, v, R_mx);
    }
    bool isValidBST(TreeNode* root) {
        return validBST(root, LLONG_MIN, LLONG_MAX);
    }
};
