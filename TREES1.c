#include <stdio.h>
#include <stdlib.h>
struct node {
   int value;
   struct node* left;
   struct node* right;
};
// Inorder traversal
void InOrder(struct node* root)
 { FILE *fp1;
 fp1=fopen("in.txt","w");
   if (root == NULL) return;
   InOrder(root->left);
   fprintf(fp1,"%d ", root->value);
   printf("%d ", root->value);
   InOrder(root->right);
   fprintf(fp1,"%d ", root->value);
   fclose(fp1);
}
// PreOrder traversal
void PreOrder(struct node* root)
 {
     FILE *fp2;
 fp2=fopen("pre.txt","w");
  if (root == NULL) return;
  fprintf(fp2,"%d ", root->value);
  printf("%d ", root->value);
  PreOrder(root->left);
  PreOrder(root->right);
  fclose(fp2);
}
// PostOrder traversal
void PostOrder(struct node* root)
 {
     FILE *fp3;
 fp3=fopen("post.txt","w");
  if (root == NULL) return;
  PostOrder(root->left);
  PostOrder(root->right);
  fprintf(fp3,"%d ", root->value);
  printf("%d ", root->value);
  fclose(fp3);
}
// Create a new Node
struct node* createNode(int value) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->value = value;
  newNode->left = NULL;
  newNode->right = NULL;
  return newNode;
}
int main() {
    int a[7];
    int i;
    for(i=0;i<7;i++)
    {
        a[i]=rand();
        //fprintf(fp1,"%d ",a[i]);
        printf("%d ",a[i]);
    }
    printf("\n");
i=0;
  struct node* root = createNode(a[i]);
  root->left = createNode(a[i+1]);
  root->right = createNode(a[i+2]);
  root->left->left = createNode(a[i+3]);
  root->left->right = createNode(a[i+4]);
  root->right->left = createNode(a[i+5]);
  root->right->right = createNode(a[i+6]);
  printf("Inorder traversal:\t");
  InOrder(root);
  printf("\n");
  printf("\PreOrder traversal:\t");
  PreOrder(root);
  printf("\n");
  printf("\nPostOrder traversal:\t");
  PostOrder(root);
  printf("\n");
}
