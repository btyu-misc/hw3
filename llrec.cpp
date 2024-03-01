#include "llrec.h"
//#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void pivotHelp(Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == NULL) {
        smaller = NULL;
        larger = NULL;
    }
    else if (head->val > pivot) { 
        //std::cout << head->val << " greater than pivot " << pivot << std::endl;
        larger = head; //since it's a direct reference it will change previouslarger->next
        pivotHelp(head->next, smaller, larger->next, pivot);
    }
    else if (head->val <= pivot) {
        //std::cout << head->val << " less than or equal to pivot " << pivot << std::endl;
        smaller = head; 
        pivotHelp(head->next, smaller->next, larger, pivot);
    }
}

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    pivotHelp(head, smaller, larger, pivot); 
    head = NULL;
}

