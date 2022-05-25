class MyLinkedList {
public:
    const static int DUMMYVALUE = INT_MIN;
    int len;

    class LinkedListNode{
    public:
        int value;
        LinkedListNode* next;
        LinkedListNode(LinkedListNode* nxt, int val){
            value = val;
            next = nxt;
        }
    };
    LinkedListNode* head;

    MyLinkedList() {
        len = 0;
        head = new LinkedListNode(NULL, DUMMYVALUE);
    }

    int get(int index) {// O(N)
        if(index<0 || index>=len) return -1;
        auto curr = head -> next;// head
        while(index--){
            curr = curr -> next;
        }
        return curr->value;
    }

    void addAtHead(int val) {
        addAtIndex(0, val);
    }

    void addAtTail(int val) {
        addAtIndex(len, val);
    }
    // particular index(addAtIndex/deleteAtIndex) a add/delete korte chaile (curr = head) theke start korbo
    void addAtIndex(int index, int val) {// O(N)
        if(index<0 || index>len) return;
        auto curr = head;// head
        while(index--){
            curr = curr -> next;
        }
        auto next = curr -> next;
        curr -> next = new LinkedListNode(NULL, val);
        curr -> next -> next = next;
        len++;
    }

    // idx = 2 hoile 2 no idx er node delete kora lgbe..tokhn oi node er aag prjnto curr pointer ke ana lgbe..oi node borabor ana jabe na..tai (curr = head) dibo
    void deleteAtIndex(int index) {// O(N)
        if(index<0 || index>=len) return;
        auto curr = head;
        while(index--){
            curr = curr->next;
        }
        auto dumpNode = curr -> next;
        curr -> next = curr -> next -> next;
        delete(dumpNode);
        len--;
    }
};

