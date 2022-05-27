// TC = O(1)
// MC = O(1)
class Solution {
public:
    void deleteNode(ListNode* node) {
        node->val = node->next->val;// copy the next node val into curr(ListNode* node) node
        auto dumpNode = node->next;
        node->next = node->next->next;
        delete(dumpNode);
        return;
    }
};
