// TC = O(N) where N is the number of total nodes in the tree
// MC = O(N)
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {

        vector<vector<int> > nodes;
        if(!root) return nodes;
        queue<TreeNode*> Q;
        Q.push(root);
        int level = -1;

        while(!Q.empty()){
            int len = Q.size();
            level++;
            vector<int> intermidiate;

            for(int i = 0; i < len; i++){
                TreeNode* u = Q.front();
                Q.pop();
                intermidiate.push_back(u->val);
                if(u->left) Q.push(u->left);
                if(u->right) Q.push(u->right);
            }
            if(level&1){// odd
                reverse(intermidiate.begin(), intermidiate.end());
            }
            nodes.push_back(intermidiate);
        }
        return nodes;
    }
};
