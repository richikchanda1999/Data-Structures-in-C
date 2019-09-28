#include <stdio.h>
#include <stdlib.h>
#include "DoubleLinkedList.h"

Node* createNode(int x) {
	Node *newNode = (Node *) malloc(sizeof(Node));
	newNode -> x = x;
	newNode -> prev = NULL;
	newNode -> next = NULL;
	return newNode;
}

int insertAtPos(Node **head, int x, int index) {
	if(index < 0) return 0;
	else {
		Node *newNode = createNode(x);
		if((index == 0 && *head == NULL) || (*head == NULL)) {
			*head = newNode;
			return 1;
		}
		else if(index == 0) {
			newNode->next = *head;
			*head = newNode;
			return 1;
		}
		else {
			Node *temp = *head;
			while(--index && temp != NULL) temp = temp->next;
			if(temp == NULL) return 0;
			else {
				newNode->prev = temp;
				newNode->next = temp->next;
				temp->next = newNode;
				newNode->next->prev = newNode;
				return 1;
			}
		}
	}
}

void insertAtBeg(Node **head, int x) {
	insertAtPos(head, x, 0);
}

void insertAtEnd(Node **head, int x) {
	if(*head == NULL) insertAtPos(head, x, 0);
	else {
		Node *temp = *head;
		while(temp->next != NULL) {
			temp = temp->next;
		}
		Node *newNode = createNode(x);
		newNode->prev = temp;
		temp->next = newNode;
	}
}

int printList(Node *head) {
	if(head == NULL) return 0;
	else {
		Node* temp = head;
		while(1) {
			printf("%d <=> ", temp -> x);
			temp = temp -> next;
			if(temp == NULL) break;
		}
		printf("\n");
		return 1;
	}
}

Node* searchKey(Node** head, int x) {
	if(*head == NULL) return NULL;
	Node *temp = *head;
	while(1) {
		if (temp == NULL) return NULL;
		if(temp -> x == x) return temp;
		temp = temp -> next;
	}
}

Node* searchIndex(Node** head, int index) {
	if(*head == NULL) return NULL;
	Node *temp = *head;
	while(index--) {
		if (temp == NULL) return NULL;
		temp = temp -> next;
	}
	return temp;
}

int deleteKey(Node **head, int x) {
	if(*head == NULL) return 0;
	Node *temp = *head;
	if(temp->x == x && temp->next != NULL) {
		temp->next->prev = NULL;
		*head = temp->next;
		return 1;
	}
	else if(temp->x == x) {
		*head = NULL;
		return 1;
	}
	while(temp != NULL) {
		if(temp->x == x && temp->next == NULL){
			temp->prev->next = NULL;
			return 1;
		}
		else if(temp->x == x) {
			printf("%d\n", temp->x);
			temp->prev->next = temp->next;
			temp->next->prev = temp->prev;
			return 1; 
		}
		temp = temp->next;
	}
	return 0;
}

int deleteIndex(Node **head, int index) {
	if(*head == NULL) return 0;
	Node *temp = *head;

	if(index == 0) return (deleteKey(head, temp->x));

	while(index-- && temp != NULL) 
		temp = temp->next;
	
	if(temp == NULL) return 0;
	if(temp->next == NULL) {
		temp->prev->next = NULL;
		return 1;
	}
	printf("%d\n", temp->x);
	temp->prev->next = temp->next;
	temp->next->prev = temp->prev;
	return 1;
}

void deleteList(Node **head) {
	while(*head != NULL) deleteIndex(head, 0);
}

Node* nthNode(Node **head, int n) {
	return(searchIndex(head, n - 1));
}

Node* nthNodeEnd(Node **head, int n) {
	Node *temp = *head;
	Node *temp1 = nthNode(head, n);
	if(temp1 != NULL) {
		while(temp1 -> next != NULL) {
			temp = temp -> next;
			temp1 = temp1 -> next;
		}
		return temp;
	}
	else return NULL;
}

int size(Node **head) {
	if(*head == NULL) return 0;
	int size = 0;
	Node *temp = *head;
	while(temp != NULL) {
		size++;
		temp = temp -> next;
	}
	return size;
}

Node* midElement(Node **head) {
	if(*head == NULL) return NULL;
	Node *p = *head;
	Node *q;
	if(p -> next != NULL) q = p -> next;
	else return NULL;
	while(1) {
		p = p->next;
		int ctr = 2;
		while(ctr--) {
			if(q->next != NULL) q = q->next;
			else return p;
		}
	}
}

Node *reverseList(Node **head) {
        if(*head == NULL) return NULL;
        Node *newHead = NULL;
        Node *temp = *head;
        while(temp != NULL) {
                insertAtBeg(&newHead, temp->x);
                temp = temp->next;
        }
        deleteList(head);
        return newHead;
}      

/*int main() {
	Node *head = NULL;
	do {
		printf("\t\t*** Double Linked List ***\n");
		printf("1. Insert element at beginning\n");
		printf("2. Insert element at end of list\n");
		printf("3. Insert element at particular position\n");
		printf("4. Delete element from the list given the key\n");
		printf("5. Delete an element from the list given the index of the node\n");
		printf("6. Search an element from the list given the key\n");
		printf("7. Delete the linked list\n");
		printf("8. Search an element from the list given the index of the node\n");
		printf("9. Get the nth node of the list\n");
		printf("10. Get the nth node from the end of the list\n");
		printf("11. Count the number of nodes in the list\n");
		printf("12. Get the middle element of the list\n");
		printf("13. Print the list\n");
		printf("14. Reverse the list\n");
		//printf("15. Check if it contains a loop\n");
		printf("15. Exit\n");
		printf("\nEnter the operation you want to perform : ");
		int ch;
		scanf("%d", &ch);
		int x, index, ret;
		Node *f = NULL;

		switch(ch) {
			case 1:
				printf("Enter the key to add to the beginning : ");
				scanf("%d", &x);
				insertAtBeg(&head, x);
				printf("Successfully added element!\n");
				break;

			case 2:
				printf("Enter the key to add to the end : ");
				scanf("%d", &x);
				insertAtEnd(&head, x);
				printf("Successfully added element!\n");
				break;

			case 3:
				printf("Enter the key to add : ");
				scanf("%d", &x);
				printf("Enter the position to add the element : ");
				scanf("%d", &index);
				ret = insertAtPos(&head, x, index);
				if(ret == 0) printf("Could not add element to the list!\n");
				else printf("Successfully added element!\n");
				break;

			case 4: printf("Enter key to delete : ");
				scanf("%d", &x);
				while(1) {
					ret = deleteKey(&head, x);
					printList(head);
					if(ret == 0) break;
				}
				printf("Done\n");
				break;

			case 5: printf("Enter index to delete : ");
				scanf("%d", &index);
				ret = deleteIndex(&head, index);
				if(ret) printf("Deleted index!\n");
				else printf("Index not found!\n");
				break;

			case 6: 
				printf("Enter key to search : ");
				scanf("%d", &x);
				f = searchKey(&head, x);
				if(f != NULL) printf("Value of node : %d\n", f -> x);
				else printf("Key not present!\n");
				break;

			case 7: deleteList(&head);
				break;

			case 8: 
				printf("Enter index to search for : ");
				scanf("%d", &index);
				f = searchIndex(&head, index);
				if(f != NULL) printf("Value of node : %d\n", f -> x);
				else printf("Index not found!\n");
				break;

			case 9 : printf("Enter the node number : ");
				 scanf("%d", &x);
				 f = nthNode(&head, x);
				 if(f != NULL) printf("Value of the node : %d\n", f -> x);
				 else printf("Node not found!\n");
				 break;

			case 10 : printf("Enter the node number from the end : ");
				  scanf("%d", &x);
				  f = nthNodeEnd(&head, x);
				  if(f != NULL) printf("Value of the node : %d\n", f -> x);
				  else printf("Node not found!\n");
				  break;

			case 11: printf("Number of nodes in the list are : %d\n", size(&head));
				 break;

			case 12: 
				 f = midElement(&head);
				 if(f != NULL) printf("Value of the middle node : %d\n", f -> x);
				 else printf("Node not found!\n");
				 break;

			case 13: ret = printList(head);
				 if(!ret) printf("No elements to be printed!\n");
				 break;

			case 14: head = reverseList(&head);
				 printf("List reversed!\n");
				 break;

			case 15: break;
		}
		printf("\n");
		if(ch == 15) {
			if(f != NULL) free(f);
			deleteList(&head);
			break;
		}

	}while(1);

	return 0;
}*/
