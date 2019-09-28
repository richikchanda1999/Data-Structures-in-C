#include <stdio.h>
#include <stdlib.h>
#include "BinarySearchTree.h"

int main() {
	Tree *root = NULL;
	do {
		printf("1. Insert an element in the BST\n");
		printf("2. Delete an element from the BST\n");
		printf("3. Search an element in the given BST\n");
		printf("4. Find out the inorder traversal of the given BST\n");
		printf("5. Find out the preorder traversal of the given BST\n");
		printf("6. FInd out the postorder traversal of the given BST\n");
		printf("7. Find out the levelorder traversal of the given BST\n");
		printf("8. Find out the height of the BST\n");
		printf("9. Find out the height of a given node of the BST\n");
		printf("10. Find out the depth of a given node of the BST\n");
		printf("11. Find out the predecessor of a given node of the BST\n");
		printf("12. Find out the successor of a given node of the BST\n");
		printf("13. Find out the least common ancestor of a given node in BST\n");
		printf("14. Find out the total number of nodes present in the tree\n");
		printf("15. Delete the Tree\n");
		printf("16. Construct Tree using In-Order and Pre-Order Traversals\n");
		printf("17. Construct Tree using In-Order and Post-Order Traversals\n");
		printf("18. Exit\n");
		printf("Please enter your choice : ");

		int ch, x, ret, *a, *pos = 0, i, *in, *post, *pre;
		Tree *temp = NULL;
		scanf("%d", &ch);
		
		switch(ch) {
			case 1: printf("Enter value to be entered into BST : ");
				scanf("%d", &x);
				insert(&root, x);
				break;
				
			case 2: printf("Enter value to be deleted : ");
				scanf("%d", &x);
				ret = deleteNode(&root, x);
				if(ret == -1) printf("Element could not be deleted!\n");
				else printf("Element deleted successfully!\n");
				break;
				
			case 3: printf("Enter element to be searched for : ");
				scanf("%d", &x);
				temp = search(root, x);
				if(temp == NULL) printf("Element not present!\n");
				else printf("Element present in the Binary Search Tree\n");
				break;
			
			case 4: printf("");
				int *a = (int *) malloc(countNodes(root) * sizeof(int));
				int pos = 0;
				inOrder(root, &a, &pos);
				int i = 0;
				for(; i < pos ; i++) printf("%d, ", a[i]);
				break;

			case 5: printf("");
                                a = (int *) malloc(countNodes(root) * sizeof(int));
                                pos = 0;
                                preOrder(root, &a, &pos);
                                for(i = 0 ; i < pos ; i++) printf("%d, ", a[i]);
                                break;
				
			case 6: printf("");
                                a = (int *) malloc(countNodes(root) * sizeof(int));
                                pos = 0;
                                postOrder(root, &a, &pos);
                                //int i = 0;
                                for(i = 0; i < pos ; i++) printf("%d, ", a[i]);
                                break;

			case 7: printf("");
                                a = (int *) malloc(countNodes(root) * sizeof(int));
                                pos = 0;
                                levelOrder(&root, &a, &pos);
                                //int i = 0;
                                for(i = 0; i < pos ; i++) printf("%d, ", a[i]);
                                break;
	
			case 8: ret = height(root);
				printf("Height of tree = Height of root node = %d\n", ret);
				break;

			case 9: printf("Enter node whose height is to be found : ");
				scanf("%d", &x);
				temp = search(root, x);
				if(temp != NULL) {
					ret = height(temp); 
					printf("Height of the node is : %d\n", ret);
				}
				else printf("Such node is not present!\n");
				break;

			case 10:printf("Enter node whose depth needs to be found : ");
				scanf("%d", &x);
				temp = search(root, x);
				if(temp != NULL) {
					ret = depth(root, temp);
					printf("Depth of the node is : %d\n", ret);
				} else printf("Depth of such node cannot be found!\n");
				break;
				
			case 11:printf("Enter node whose predecessor needs to be found : ");
                                scanf("%d", &x);
                                temp = search(root, x);
                                if(temp != NULL) {
                                        ret = predecessor(&root, &temp);
                                        if(ret != -1) printf("Inorder Predecessor is : %d\n",
ret);
                                        else printf("Inorder Predecessor not present!\n");
                                } else printf("Node not present!\n"); 
				break;

			case 12:printf("Enter node whose successor needs to be found : ");
                                scanf("%d", &x);
                                temp = search(root, x);
                                if(temp != NULL) {
                                        ret = successor(&root, &temp);
                                        if(ret != -1) printf("Inorder Successor is : %d\n",
ret);
                                        else printf("Inorder Successor not present!\n");
                                } else printf("Node not present!\n");
				break;

			case 13: printf("Enter node 1 whose Least Common Ancestor needs to be found : ");
                                scanf("%d", &x);
                                Tree *temp1 = search(root, x);

				printf("Enter node 2 whose Least Common Ancestor needs to be found : ");
                                scanf("%d", &x);
                                Tree *temp2 = search(root, x);

                                if(temp1 != NULL && temp2 != NULL) {
                                        ret = leastCommonAncestor(&root, &temp1, &temp2);
                                        if(ret != -1) printf("Least Common Ancestor is : %d\n",
ret);
                                        else printf("Least Common Ancestor not present!\n");
                                } else printf("Node not present!\n");
				break;
		
			case 14: ret = countNodes(root);
				printf("No. of nodes : %d\n", ret);
				break;

			case 15: deleteTree(&root);
				 root = NULL;
				 break;

			case 16:printf("The previous tree will be deleted!\nEnter no. of nodes in the tree : ");
				scanf("%d", &ret);
				in = (int *) malloc(sizeof(int) * ret);
				pre = (int *) malloc(sizeof(int) * ret);
				printf("Enter Pre-Order Traversal : ");
				for(i = 0 ; i < ret ; i++) scanf("%d", pre + i);
				printf("Enter In-Order Traversal : ");
				for(i = 0 ; i < ret ; i++) scanf("%d", in + i);
				deleteTree(&root);
				root = NULL;
				i = 0;
				constructUsingPre(&root, &in, &pre, 0, ret - 1, &i);
				printf("Tree constructed!\n");
				break;
			
			case 17:printf("The previous tree will be deleted!\nEnter no. of nodes in the tree : ");
                                scanf("%d", &ret);
                                in = (int *) malloc(sizeof(int) * ret);
                                post = (int *) malloc(sizeof(int) * ret);
                                printf("Enter Post-Order Traversal : ");
                                for(i = 0 ; i < ret ; i++) scanf("%d", post + i);
                                printf("Enter In-Order Traversal : ");
                                for(i = 0 ; i < ret ; i++) scanf("%d", in + i);
                                deleteTree(&root);
                                root = NULL;
                                i = ret - 1;
                                constructUsingPost(&root, &in, &post, 0, ret - 1, &i);
                                printf("Tree constructed!\n");
                                break;

			case 18: break;
		}	

		if(ch == 18) {
			printf("Execution stopped!\n");
			break;
		}

		printf("\n");
	}while(1);
	return 0;
}
