// TC = O(logN * NlogN) where N is the total no of nodes
// MC = O(N)
class Solution {
public:
    map<int, vector<pair<int, pair<int,int>>> > levelWiseNode;
    int rank = 0;

    void traverse(TreeNode* u, int order = 0, int level = 0){// O(N), N = all nodes
        if(!u) return;
        levelWiseNode[order].push_back({level, {rank++, u->val}});
        traverse(u->left, order - 1, level + 1);
        traverse(u->right, order + 1, level + 1);
    }
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int> > vertOrder;
        traverse(root);

        // O(logN) , at most logN level possible
        for(auto nodeList: levelWiseNode){// map

            auto nodes = nodeList.second;// map er vector
            sort(nodes.begin(), nodes.end());// O(NlogN) for N nodes

            vector<int> levelNodes;
            for(auto node: nodes){// map er moddhe vector er value
                levelNodes.push_back(node.second.second);
            }
            vertOrder.push_back(levelNodes);

        }
        return vertOrder;
    }
};
