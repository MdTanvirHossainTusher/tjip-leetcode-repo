// TC = O(N)
// MC = O(1)
// cycle thakle node a NULL thkbe na
// hare and tortoise technique
class Solution {
public:
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        auto slow = head;
        auto fast = head;
        while(fast->next && fast->next->next){
            slow = slow -> next;
            fast = fast -> next -> next;
            if(slow == fast) return true;
        }
        return false;
    }
};

/**********************************/
// TC = O(N)
// MC = O(N)
// cycle thakle node a NULL thkbe na
class Solution {
public:
    unordered_map<ListNode*, int> counter;
    bool hasCycle(ListNode *head) {
        if(head == NULL) return false;
        counter[head]++;
        if(counter[head] == 2) return true;
        return hasCycle(head -> next);
    }
};
