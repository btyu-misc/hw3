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

//PREVIOUS IMPLEMENTATION (STILL WORKS), uses tail recursion. I wanted to try implementing
//a head recursion implementation of llpivot, which is the above function (with a helper function)

/*
void llpivot(Node*& head, Node*& smaller, Node*& larger, int pivot) {
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
*/
