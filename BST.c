#include<stdio.h> 
#include<stdlib.h> 
   
struct node 
{ 
    int key; 
    struct node *left, *right; 
}; 
struct node *newNode(int item) 
{ 
    struct node *temp =  (struct node *)malloc(sizeof(struct node)); 
    temp->key = item; 
    temp->left = temp->right = NULL; 
    return temp; 
}
void inorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        inorder(root->left); 
        printf("%d ", root->key); 
        inorder(root->right); 
    } 
}
void preorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
	printf("%d ", root->key); 
        preorder(root->left); 
        preorder(root->right); 
    } 
}
void postorder(struct node *root) 
{ 
    if (root != NULL) 
    { 
        postorder(root->left); 
        postorder(root->right); 
	printf("%d ", root->key); 
    } 
}
struct node* insert(struct node* node, int key) 
{ 
    if (node == NULL) return newNode(key); 
    if (key < node->key) 
        node->left  = insert(node->left, key); 
    else if (key > node->key) 
        node->right = insert(node->right, key);    
  
    return node; 
} 

int main() 
{
    struct node *root = NULL; 
	int val,ch;
while(1)
{	printf("\n1 insert\n2 print_in_inorder\n3 print_in_preorder\n4 print_in_postorder\n5 exit\n");
    scanf("%d",&ch);
	switch(ch)
{
	case 1: scanf("%d",&val);
	    	root =insert(root,val); 
		break;
	case 2: inorder(root); 
		break;
	case 3: preorder(root); 
		break;
	case 4: postorder(root); 
		break;
	case 5: exit(0);
	default: printf("wrong choice\n");
}
 }  
    return 0; 
} 


