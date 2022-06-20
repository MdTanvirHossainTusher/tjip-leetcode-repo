// TC = O(N)
// MC = O(N)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        unordered_map<Node*, Node*> copies;
        auto curr = head;
        if(head == NULL) return head;
        while(curr){
            copies[curr] = new Node(curr->val);
            curr = curr->next;
        }
        auto copy = head;
        while(copy){
            copies[copy]->next = copies[copy->next];
            copies[copy]->random = copies[copy->random];
            copy = copy->next;
        }
        return copies[head];
    }
};

/****************************************/
// TC = O(N)
// MC = O(1)
