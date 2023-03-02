#include "llrec.h"

//*********************************************
// Provide your implementation of llpivot below
//*********************************************

void llpivot (Node*& head, Node*& smaller, Node*& larger, int pivot){
  
	if(head == NULL) {
		smaller = NULL;
		larger = NULL;
		return;
	} 
	
	llpivot(head->next, smaller, larger, pivot);
	Node* temp = head; 
	head = NULL; 

	if (temp->val > pivot) 
	{
		if (larger) 
		{
			temp->next = larger;
		}	
		larger = temp;
	} 
	else
	{
		if (smaller) 
		{
			temp->next = smaller;
		}
		smaller = temp;
	}	
}
