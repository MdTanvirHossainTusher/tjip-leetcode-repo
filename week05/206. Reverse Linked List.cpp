// TC = O(N)
// MC = O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prv, *curr, *next;
        if(head == NULL) return head;
        prv = NULL;
        curr = head;

        while(curr){
            auto next = curr->next;
            curr -> next = prv;
            prv = curr;
            curr = next;
        }
        return prv;
    }
};

/**********************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    ListNode* reverseList(ListNode* head, ListNode* prv = NULL) {
        if(head == NULL) return prv;
        auto next = head -> next;
        head->next = prv;
        return reverseList(next, head);
    }
};
