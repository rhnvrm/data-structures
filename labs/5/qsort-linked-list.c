#include <stdio.h>
#include <stdlib.h>

typedef struct node_node{
	int data;
	struct node_node *next;
} node;

node* getTail(node *cur)
{
    while (cur != NULL && cur->next != NULL)
        cur = cur->next;
    return cur;
}

void qs(node* head, node* till, node** ret){
	int nlo, nhi;
    node *lo, *hi, *q, *p;

    while (head != NULL) {

        nlo = nhi = 0;
        lo = hi = NULL;
        q = head;
        p = head->next;

        while (p != NULL) {
            q = p->next;
            if (p->data <= head->data) {
                p->next = lo;
                lo = p;
                ++nlo;
            } else {
                p->next = hi;
                hi = p;
                ++nhi;
            }
            p = q;
        }

        if (nlo < nhi) {
            qs(lo, head, ret);
            ret = &head->next;
            head = hi;        
        } else {
            qs(hi, till, &head->next);
            till = head;
            head = lo;        
        }
    }

    *ret = till;
}   

void printList(node *p)
{
    while (p != NULL)
    {
        printf("%d -> ", p->data);
        p = p->next;
    }
    printf("NULL\n");
}

void push(node** head_ref, int new_data)
{

    node* new_node = (node*)malloc(sizeof(node));
    new_node->data  = new_data;
    new_node->next = (*head_ref);

    (*head_ref)    = new_node;
}



int main(){

	int number_of_elements = 0, temp;

	node* head = NULL;

	scanf("%d", &number_of_elements);

	for(int i = 0; i < number_of_elements; i++){
		scanf("%d", &temp);
		push(&head, temp);
	}


	printList(head);
	qs(head, NULL, &head);
	printList(head);
	//printList(getTail(head));
	return 0;
}