#include <iostream>
#include <cmath>
using namespace std;
struct ListNode{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

ListNode *createNewNode(int value){

    ListNode *new_node = (ListNode*)malloc(sizeof(ListNode));
    new_node->val = value;
    new_node->next = NULL;

    return new_node;
}

ListNode *addTwoNumbers(ListNode *l1, ListNode *l2){

    int exceed = 0;
    int digit = 0;
    int to_add = 0;
    bool first = false;

    ListNode *result = NULL;
    ListNode *head = NULL;
    ListNode *previous = NULL;

    while(l1 != NULL && l2 != NULL){

        if(l1 == NULL) digit = l2->val;
        else if(l2 == NULL) digit = l1->val;
        else digit = l1->val + l2->val;

        if(to_add > 0){
            digit += to_add;
            to_add = 0;
        }
        if(digit >= 10){
            exceed = digit - 10;
            result = createNewNode(exceed);
            to_add = 1;
        }
        else{
            result = createNewNode(digit);
        }

        if(!first){
            head = result;
            first = true;

        }
        else{
            previous->next = result;
        }

        previous = result;

        l1 = l1->next;
        l2 = l2->next;
    }

    return head;
}



int main(){

    ListNode *l1 = createNewNode(2);
    l1->next = createNewNode(4);
    l1->next->next = createNewNode(3);

    ListNode *l2 = createNewNode(5);
    l2->next = createNewNode(6);
    l2->next->next = createNewNode(4);

    addTwoNumbers(l1, l2);

    return 0;
}
