

/*
 * Date:2021-12-15 09:47
 * filename:03_rearrange_list.c
 *
 */

#include <stdio.h>
#include <stdlib.h>

struct node
{
    int value;
    struct node *next;
};

typedef struct node LNode;

void rearrange(struct node *list)
{
   struct node *p, * q;
   int temp;
   if ((!list) || !list -> next)
      return;
   p = list;
   q = list -> next;
   while(q)
   {
       temp = p -> value;
       p -> value = q -> value;
       q -> value = temp;
       p = q -> next;
       q = p ? p -> next:0;
   }
}

void print(struct node* list) {
	if (list == NULL) 
		return ;

	struct node* phead = list;
	while (phead) {
		printf("%d ",phead->value);
		phead = phead->next;
	}
}

void Destroy(struct node* list) {
	struct node* p = list;
	while (list != NULL) {
		list = p->next;
		free(list);
		list = NULL;
		p = list;
	}
}


int main() {
	LNode* node1 = (LNode*)malloc(sizeof(LNode));
	LNode* node2 = (LNode*)malloc(sizeof(LNode));
	LNode* node3 = (LNode*)malloc(sizeof(LNode));
	LNode* node4 = (LNode*)malloc(sizeof(LNode));
	LNode* node5 = (LNode*)malloc(sizeof(LNode));
	LNode* node6 = (LNode*)malloc(sizeof(LNode));
	LNode* node7 = (LNode*)malloc(sizeof(LNode));

	node1->value = 1;
	node2->value = 2;
	node3->value = 3;
	node4->value = 4;
	node5->value = 5;
	node6->value = 6;
	node7->value = 7;

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;
	node5->next = node6;
	node6->next = node7;
	node7->next = NULL;

	LNode* head = node1;

	rearrange(head);

	print(head);
	printf("\n");

	Destroy(head);
}
