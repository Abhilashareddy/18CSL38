#include <stdio.h>
#include <stdlib.h>

struct BST {
	int data;
	struct BST *left,*right;
};

typedef struct BST *NODE;

// create
// search
// inorder
// preorder
// postorder

NODE create(NODE node, int data){
	if(node == NULL) {
		NODE temp = (NODE) malloc(sizeof(struct BST));
		temp -> data = data;
		temp -> left = temp ->right = NULL;
		return temp;
	}
	if(data < node-> data)
		node -> left = create(node->left, data);
	else if (data>node->data)
		node -> right = create(node->right, data);
	else
		printf("Duplicate data found\n");
	return node;
}

NODE search(NODE node, int data){
	if(node==NULL)
		printf("Element not found \n");
	else if(data < node->data)
		node->left = search(node->left,data);
	else if (data>node->data)
		node->right = search(node->right,data);
	else
		printf("Element found %d", node->data);
	return node;
}

void inorder(NODE node){
	if(node!=NULL){
		inorder(node->left);
		printf("%d\t", node->data);
		inorder(node->right);
	}
}

void preorder(NODE node){
        if(node!=NULL){
                printf("%d\t", node->data);
                preorder(node->left);
                preorder(node->right);
        }
}

void postorder(NODE node){
        if(node!=NULL){
                postorder(node->left);
                postorder(node->right);
                printf("%d\t", node->data);
        }
}

void main(){
	int ch, n, value,i;
	NODE root = NULL;
	while(1){
		printf("\n1. Insertion\n2. Search\n3. Inorder\n4. Preorder\n5. Postorder\n6. Exit\n\tChoice: ");
		scanf("%d",&ch);
		switch(ch){
			case 1:
			printf("Enter no. of data: ");
			scanf("%d", &n);
			printf("Enter data: ");
			for(i=0;i<n;i++){
				scanf("%d", &value);
				root = create(root, value);
			}
			break;
			case 2:
				printf("Enter search element: ");
				scanf("%d",&value);
				root = search(root,value);
				break;
			case 3:
				printf("Inorder\n");
				inorder(root);
				break;
			case 4:
                                printf("Preorder\n");
                                preorder(root);
                                break;
			case 5:
                                printf("Postorder\n");
                                postorder(root);
                                break;
			case 6:
				exit(0);
			default:
				printf("Wrong option\n");

		}

	}


}
