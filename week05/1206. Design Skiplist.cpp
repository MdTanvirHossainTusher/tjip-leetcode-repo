// TC = O(logN)
// MC = O(logN)
class Skiplist {
public:
    const static int DUMMYVALUE = -1;

    class Node{
    public:
        int val;
        Node *next, *down;
        Node(int _v, Node* _n, Node* _d){
            val = _v;
            next = _n;
            down = _d;
        }
    };

    Node* head;
    random_device rd;

    Skiplist() {
        head = new Node(DUMMYVALUE, NULL, NULL);
    }

    bool search(int target) {// TC - O(logN), MC - O(1)
        auto curr = head;
        while(curr){
            while(curr->next && curr->next->val < target){
                curr = curr->next;
            }
            if(curr->next && curr->next->val == target) return true;
            curr = curr->down;
        }
        return false;
    }

    void add(int target) {// TC - O(logN), MC - O(logN)
        stack<Node*> path;
        auto curr = head;

        while(curr){
            while(curr->next && curr->next->val < target){
                curr = curr->next;
            }
            path.push(curr);
            curr = curr->down;
        }
        Node* down = NULL;
        bool goUp = true;

        while(goUp && !path.empty()){// MC - O(logN)
            curr = path.top();
            path.pop();
            curr->next = new Node(target, curr->next, down);
            down = curr->next;
            goUp = (rd() % 100) < 50;
        }
        // sb layer a target value bosano hoye gele r target value bosanor jayga thkbe na..tai tkhn notun layer create kora lgbe..and head update kora lgbe
        if(goUp) head = new Node(DUMMYVALUE, NULL, head);
    }

    bool erase(int target) {// TC - O(logN), MC - O(1)
        auto curr = head;
        bool found = false;
        while(curr){
            while(curr->next && curr->next->val < target){
                curr = curr->next;
            }
            if(curr->next && curr->next->val == target){
                auto dumpNode = curr ->next;
                curr->next = curr -> next -> next;
                delete(dumpNode);
                found = true;
            }
            curr = curr -> down;
        }
        return found;
    }
};
