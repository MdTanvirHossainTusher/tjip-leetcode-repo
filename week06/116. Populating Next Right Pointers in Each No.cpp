// TC = O(N)
// MC = O(N); N is total no of nodes in the tree
class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        queue<Node*> nodes;
        nodes.push(root);
        while(!nodes.empty()){
            int len = nodes.size();
            for(int i = 0; i < len; i++){
                Node* u = nodes.front();
                nodes.pop();
                if(i + 1 < len){
                    u->next = nodes.front();
                }
                if(u->left) nodes.push(u->left);
                if(u->right) nodes.push(u->right);
            }
        }
        return root;
    }
};
