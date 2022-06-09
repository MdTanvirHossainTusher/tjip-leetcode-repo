// TC = O(N)
// MC = O(N) where N is total no of nodes in the Binary Tree
class Solution {
public:
    // postorder traversal
    int getHeight(TreeNode* &curr, unordered_map<int, vector<int> > &currLevelNodes){
        if(!curr) return -1;
        int left = getHeight(curr->left, currLevelNodes);
        int right = getHeight(curr->right, currLevelNodes);

        int height = max(left, right) + 1;
        currLevelNodes[height].push_back(curr->val);
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        unordered_map<int, vector<int> > currLevelNodes;
        vector<vector<int> > res;

        int height = getHeight(root, currLevelNodes);
        for(int i = 0; i <= height; i++){
            res.push_back(currLevelNodes[i]);
        }
        return res;
    }
};

/*************************************/
// TC = O(N)
// MC = O(N) where N is total no of nodes in the Binary Tree
class Solution {
public:
    // postorder traversal
    int getHeight(TreeNode* &curr, vector<vector<int> > &currLevelNodes){

        if(!curr) return -1;
        int left = getHeight(curr->left, currLevelNodes);
        int right = getHeight(curr->right, currLevelNodes);

        int height = max(left, right) + 1;

        if(currLevelNodes.size() == height){
            // currLevelNodes.resize(height + 1, {});
            currLevelNodes.push_back({});
        }
        currLevelNodes[height].push_back(curr->val);
        return height;
    }
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int> > currLevelNodes;
        getHeight(root, currLevelNodes);
        return currLevelNodes;
    }
};
