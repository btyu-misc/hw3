#include "llrec.h"
//#include <iostream>

//*********************************************
// Provide your implementation of llpivot below
//*********************************************


void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot) {
    if (head == NULL) {
        smaller = NULL;
        larger = NULL;
        return;
    }
    else if (head->val > pivot) {
        //std::cout << head->val << "greater than " << pivot << std::endl;
        llpivot(head->next, smaller, larger, pivot);
        head->next = larger;
        larger = head;
    }
    else if (head->val <= pivot) {
        //std::cout << head->val << "less than " << pivot << std::endl;
        llpivot(head->next, smaller, larger, pivot);
        head->next = smaller;
        smaller = head; //WE'RE WORKING BACKWARDS BY USING HEAD AS A TEMP VALUE AND SETTING SMALLER TO HEAD AFTER WE SET HEAD'S NEXT
        //VALUE. NEXT TIME WE'RE IN THIS ELSE LOOP THAT ONE'S NEXT BECOMES THIS VALUE AND SMALLER BECOMES THAT HEAD VALUE
    }
    head = NULL;
}

