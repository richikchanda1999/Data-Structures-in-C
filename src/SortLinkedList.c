#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"


void selectionSort(Node **head) {
	//int n = size(head);
	Node *temp, *temp1;
	//int i, j;
	for(temp = *head ; temp->next != NULL ; temp = temp->next) {
		Node *small = temp;
		for(temp1 = temp->next ; temp1->next != NULL ; temp1 = temp1->next) {
			if(small->x > temp1->x) small = temp1;
		}
		int t = small->x;
		small->x = temp->x;
		temp->x = t;
	}
}

splitMiddle(struct node *temph,struct node **l,struct node **r)
{
	if(temph==NULL||temph->next==NULL)
	{
		*l=temph;
		*r=NULL;
		return;
	}
	struct node *t1=temph;
	struct node *t2=temph;
	while(t2->next!=NULL&&(t2->next)->next!=NULL)
	{
		t1=t1->next;
		t2=(t2->next)->next;
	}
	*l=temph;
	*r=t1->next;
	t1->next=NULL;
}

struct node *mergeLinkedLists(struct node *l,struct node *r)
{
	if (l==NULL)
		return r;
	if(r==NULL)
		return l;
	struct node *temph= NULL;
	if (l->x<=r->x)
	{
		temph=l;
		temph->next=mergell(l->next,r);
	}
	else
	{
		temph=r;
		temph->next=mergell(l,r->next);
	}
	return temph;
}

void mergeSort(struct node **head)
{
	if((*head)->next==NULL)
		return;
	struct node* l;
	struct node* r;
	splitMiddle(*head,&l,&r);
	mergeSort(&l);
	mergeSort(&r);
	*head=mergeLinkedLists(l,r);
}/*void merge(Node** low1, Node** high1, Node** low2, Node** high2) {

   }

   void mergeSort(Node **low, Node **high) {
   if(low-> next != high && low != NULL && high != NULL) {
   Node *mid = midElement(low, high);
   mergeSort(low, &mid);
   mergeSort(&(mid -> next), high);
   merge(low, &mid, &(mid->next), high);
   }
   }*/
