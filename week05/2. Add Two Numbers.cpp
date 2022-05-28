// TC = O(N)
// MC = O(N)
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {//l1 = head1, l2 = head2
        ListNode* resHead = new ListNode(-1);// DUMMYVALUE = -1
        auto curr = resHead;
        int sum = 0, carry = 0;

        while(l1 || l2 || carry){
            if(l1){
                sum += l1->val;
                l1 = l1->next;
            }
            if(l2){
                sum += l2->val;
                l2 = l2->next;
            }
            int digit = (sum + carry) % 10;
            carry = (sum + carry) / 10;

            curr->next = new ListNode(digit);
            curr = curr->next;
            sum = 0;
        }
        return resHead->next;
    }
};
