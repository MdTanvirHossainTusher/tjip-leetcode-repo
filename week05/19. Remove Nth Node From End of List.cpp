// TC = O(N)
// MC = O(1)
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        auto slow = head;
        auto fast = head;
        while(n--){
            fast = fast -> next;
        }
        // first NULL hbe jkhn first node delete korte jabo..exp = [1], n = 1
        if(fast == NULL) return head->next;
        while(fast->next != NULL){
            slow = slow -> next;
            fast = fast -> next;
        }
        slow -> next = slow -> next -> next;// desired node ke delete korar code
        return head;
    }
};
