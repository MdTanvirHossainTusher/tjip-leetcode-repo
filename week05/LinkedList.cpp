#include<bits/stdc++.h>
using namespace std;
#define DUMMYVALUE INT_MIN

class LinkedListNode{
public:
    int value;
    LinkedListNode* next;
    LinkedListNode(int val, LinkedListNode* nxt){
        value = val;
        next = nxt;
    }
};

void printList(LinkedListNode* head){
    LinkedListNode* curr = head->next;// LinkedListNode* curr = head;
    while(curr != NULL){// curr -> next != NULL
        cout<< curr -> value<< " ";
        curr = curr -> next;
    }
    cout<<"\n";
}

LinkedListNode* insertAtHead(LinkedListNode* head, int val){// O(1)
//    LinkedListNode* curr = new LinkedListNode(val, NULL);// head always dummy ke point korbe na
//    curr -> next = head;
//    head = curr;
//    return head;
    LinkedListNode* curr = new LinkedListNode(val, NULL);// head always dummy ke point korbe
    LinkedListNode* temp = head->next;
    head->next = curr;
    curr->next = temp;
    return head;
}

LinkedListNode* insertAtEnd(LinkedListNode* head, int val){// O(N)

    LinkedListNode* curr = head;
    while(curr->next){
        curr = curr -> next;
    }
    curr->next = new LinkedListNode(val, NULL);
    return head;
}

LinkedListNode* deleteFromFront(LinkedListNode* head){

    LinkedListNode* dumpNode = head->next;
    head -> next = head->next->next;
    delete(dumpNode);
    return head;
}

LinkedListNode* deleteFromEnd(LinkedListNode* head){
    LinkedListNode* prv = head->next;
    cout<<prv->value<<" -- ";
    while(prv->next->next != NULL){
        prv = prv ->next;
        cout<<prv->value<<" + ";
    }
    delete(prv->next);
    return head;
}

int main()
{
    LinkedListNode *head = new LinkedListNode(DUMMYVALUE, NULL);
    for(int i = 0; i < 0; i++){
        head = insertAtHead(head, i);
    }
//    head = deleteFromFront(head);
    head = deleteFromEnd(head);
    printList(head);
    return 0;
}

