// TC = O(N) where N is the total no of nodes in the Binary Tree
// MC = O(1)
class Codec {
public:
    string encodedString(TreeNode* &curr){
        if(!curr) return "#";
        string left = to_string(curr->val) + "," + encodedString(curr->left) + ",";
        string right = encodedString(curr->right) ;
        return left + right;

    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {// O(N)
        if(!root) return "";
        return encodedString(root);
    }

    TreeNode* decodedTree(string &data, int &pos){
        if(pos >= data.size()) return NULL;
        int start = pos;
        while(data[pos] != ',' && pos < data.size()){// jokhn , pabe tkhn stop hbe or string er lst e gele stop hbe
            pos++;
        }
        string nodeValue = data.substr(start, pos - start);// string akare node value ta nibo
        pos++;// commar(,) porer pos a gelam
        if(nodeValue == "#") return NULL;
        TreeNode* currNode = new TreeNode(stoi(nodeValue));// thn oi node value(string) ke int a convert krbo
        currNode->left = decodedTree(data, pos);
        currNode->right = decodedTree(data, pos);
        return currNode;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {// O(N)
        int pos = 0;
        return decodedTree(data, pos);
    }
};

