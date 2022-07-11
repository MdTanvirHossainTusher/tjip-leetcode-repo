// TC = O(N)
// MC = O(N) where N is the total no of nodes
class Solution {
public:
    TreeNode* generateTree(vector<int>&preorder, vector<int>&inorder, unordered_map<int,int>&indices, int L, int R, int &pos){
        if(L > R) return NULL;
        TreeNode* currNode = new TreeNode(preorder[pos++]);
        int M = indices[currNode->val];
        currNode->left = generateTree(preorder, inorder, indices, L, M - 1, pos);
        currNode->right = generateTree(preorder, inorder, indices, M + 1, R, pos);
        return currNode;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> indices;
        int pos = 0;
        for(int i =0; i<inorder.size(); i++){
            indices[inorder[i]] = i;
        }
        return generateTree(preorder, inorder, indices, 0, inorder.size()-1, pos);
    }
};
