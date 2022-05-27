// TC = O(N)
// MC = O(1)
class Solution {// case: [5,4,2,1,6,11]
public:
    ListNode* reverseList(ListNode* prv, ListNode* curr, ListNode* next){
        while(curr){
            next = curr->next;
            curr->next = prv;
            prv = curr;
            curr = next;
        }
        return prv;
    }

    int pairSum(ListNode* head) {
        auto slow = head;
        auto fast = head->next;

        while(fast->next && fast->next->next){
            slow = slow->next;
            fast = fast->next->next;
        }
        ListNode* startOfSecondHalf = slow->next;
        slow -> next = NULL;

        auto prv = reverseList(NULL, startOfSecondHalf, startOfSecondHalf->next);

        auto curr = head;
        int maxTwinSum = INT_MIN/2;

        while(curr){
            maxTwinSum = max(maxTwinSum, curr->val + prv->val);
            curr = curr->next;
            prv = prv->next;
        }
        return maxTwinSum;
    }
};

/******************************************/
// TC = O(N)
// MC = O(1)
class Solution {
public:
    int pairSum(ListNode* head) {// case: [5,4,2,1,6,11]
        auto curr = head;
        int n = 1;
        while(curr->next){
            n++;
            curr = curr->next;
        }
        auto last = curr;
        // cout<<last->val<<"++\n";// 11

        curr = head;
        n = n/2-1;
        while(n--){
            curr = curr->next;
        }

        // cout<<curr->val<<"--\n";// 2

        auto startOfSecondHalf = curr->next;// 1
        ListNode* prv = NULL;
        curr->next = prv;
        curr = startOfSecondHalf;

        while(curr){
            auto next = curr->next;
            curr->next = prv;
            prv = curr;
            curr = next;
        }
        curr = head;
        int res = INT_MIN/2, sum;

        while(curr){
            sum = curr->val + last->val;
            curr = curr->next;
            last = last->next;
            res = max(res, sum);
        }
        return res;
    }
};
