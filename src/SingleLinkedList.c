#include <stdio.h>
#include <stdlib.h>
#include "SingleLinkedList.h"

Node* createNode(int x) {
	Node *newNode = (Node *) malloc(sizeof(Node));

	newNode -> x = x;
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
                                newNode->next = temp->next;
                                temp->next = newNode;
                                return 1;
                        }
                }
        }
}

void insertAtEnd(Node **head, int x) {
	if(*head != NULL) {
		Node *temp = *head;
		while(1) {
			if(temp -> next == NULL) break;
			temp = temp -> next;
		}
		Node *newNode = createNode(x);
		temp -> next = newNode;
	}
	else insertAtPos(head, x, 0);
}

void insertAtBeg(Node **head, int x) {
	insertAtPos(head, x, 0);
}

Node* searchKey(Node **head, int x) {
	if(*head == NULL) return 0;
	Node *temp = *head;
	if(temp->x == x) return temp;
	Node *temp1 = temp -> next;
	while(temp1 != NULL) {
		if(temp1->x == x) return temp1;
		temp1 = temp1->next;
		temp = temp->next;
	}
	return NULL;
}

Node* searchIndex(Node** head, int index) {
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
	if(temp->x == x) {
		*head = temp->next;
		return 1;
	}
	Node *temp1 = temp -> next;
	while(temp1 != NULL) {
		if(temp1->x == x) {
			temp->next = temp1->next;
			return 1;
		}
		temp1 = temp1->next;
		temp = temp->next;
	}
	return 0;
}

int deleteIndex(Node **head, int index) {
	if(*head == NULL) return 0;
	Node *temp = *head;
	Node *temp1 = temp -> next;

	if(index == 0) return deleteKey(head, temp->x);

	while(--index && temp1 != NULL) {
		temp = temp->next;
		temp1 = temp1->next;
	}

	if(temp1 == NULL) return 0;
	else {
		temp->next = temp1->next;
		return 1;
	}
}

void deleteList(Node **head) {
	Node *temp;
	while(*head != NULL) {
		temp = *head;
		*head = temp -> next;
		free(temp);
	}
}

void addLists(Node **head1, Node **head2) {
	/*if(*head1 == NULL) {
		head1 = head2;
		return;
	}*/
	Node *temp = *head2;
	while(temp != NULL) {
		insertAtEnd(head1, temp->x);
		temp = temp->next;
	}
}

Node* nthNode(Node **head, int n) {
	Node *temp = *head;
	while(--n) {
		if(temp -> next == NULL) {
			//printf("Node not present!\n");
			return NULL;
		}
		temp = temp -> next;
	}
	return (temp);
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
	int size = 0;
	Node *temp = *head;
	while(temp != NULL) {
		size++;
		temp = temp -> next;
	}
	return size;
}

Node* midElement(Node **start, Node **end) {
	Node *p = *start;
	Node *q;
	if(p -> next != NULL) q = p -> next;
	else return NULL;
	while(1) {
		p = p->next;
		int ctr = 2;
		while(ctr--) {
			if(q->next != *end) q = q->next;
			else return p;
		}
	}
}

int printList(Node *head) {
	if(head == NULL) return 0;
	else {

		Node *temp = head;
		while(temp->next != NULL) {
			printf("%d --> ", temp -> x);
			temp = temp->next;
		}
		printf("%d --> \n", temp->x);
		return 1;
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
		printf("\t*** Single Linked List ***\n");
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
		printf("15. Check if it contains a circle\n");
		printf("16. Exit\n");
		printf("\nEnter the operation you want to perform : ");
		int ch;
		scanf("%d", &ch);
		int x, index, ret;
		Node *f;
		if(ch > 4 && head == NULL && ch < 15) {
			printf("The list is empty, please enter some element first!\n\n");
			continue;
		}
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
				scanf("%d", &index);
				printf("Enter the position to add the element : ");
				scanf("%d", &x);
				ret = insertAtPos(&head, index, x);
				if(ret == 0) printf("Could not add element to the list!\n");
				else printf("Successfully added element!\n");
				break;

			case 4: printf("Enter key to delete : ");
				scanf("%d", &x);
				ret = deleteKey(&head, x);
				if(!ret) printf("Key not found!\n");
				else printf("Key deleted successfully!\n");
				break;

			case 5: printf("Enter index to delete : ");
				scanf("%d", &index);
				ret = deleteIndex(&head, index);
				if(ret) printf("Index deleted!\n");
				else printf("Index not found!\n");
				break;
			case 6: 
				printf("Enter key to search : ");
				scanf("%d", &x);
				f = searchKey(&head, x);
				if(f != NULL) printf("Key found!\n");
				else printf("Key not present!\n");
				break;

			case 7: deleteList(&head);
				printf("Entire list deleted!\n");
				break;

			case 8: 
				printf("Enter index to search for : ");
				scanf("%d", &index);
				f = searchIndex(&head, index);
				if(f != NULL)
					printf("Value of node : %d\n", f -> x);
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

			case 13:
				 ret = printList(head);
				 if(!ret) printf("No elements to print!\n");
				 break;

			case 14: head = reverseList(&head);
				 break;
			
			case 15: ret = isCircle(&head);
				 if(!ret) printf("No loop present!\n");
				 else printf("Loop is present and it has %d nodes\n", ret);
				 break;

			case 16: break;

			default: printf("Oops! Choice not found!\nYou can choose from the following.\n");
		}
		if (ch == 16) {
			deleteList(&head);
			break;
		}
		printf("\n");
	}while(1);

	return 0;
}*/
