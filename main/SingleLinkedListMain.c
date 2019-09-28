#include <stdio.h>
#include <stdio.h>
#include "SingleLinkedList.h"

int main() {
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
                                 f = midElement(&head, NULL);
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
}
