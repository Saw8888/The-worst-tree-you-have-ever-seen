#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

typedef struct{
 int val;
 void *above;
 void *left;
 void *right;
}node;

node *top = NULL;
node *current = NULL;

node *newNode(int dir, int val){
 node *new = NULL;

 if (top == NULL){
  new = (node*)malloc(sizeof(node));
  if (new == NULL)
   return NULL;
  
  new->val = val;
  top = new;
  current = top;
  new->left = NULL;
  new->right = NULL;
  new->above = NULL;
 }

 else if(dir == 1){ //The new node is to the right
  new = (node*)malloc(sizeof(node));
  if (new == NULL)
   return NULL;
  
  new->val = val;
  new->left = NULL;
  new->right = NULL;
  new->above = current;
  current->right = new;
  current = current->right;
 }

 else if(dir == 0){ //The new node is to the left
  new = (node*)malloc(sizeof(node));
  if (new == NULL)
   return NULL;
  
  new->val = val;
  new->left = NULL;
  new->right = NULL;
  new->above = current;
  current->left = new;
  current = current->left;

 }
 return new;
}

void MoveUp(){
 if(current == NULL){
  printf("Error: Cannot move up when you haven't made an initial node or if you are at the top of the tree");
  return NULL;
 }
 current = current->above;
}

void printTree(){
 node *currentNode = top;
 //while(1){
  printf("%d\n",currentNode->val);
  if(currentNode->right != NULL){
   currentNode = currentNode->right;
   printf("R:%d\n",currentNode->val);
  }
  
  currentNode = top;

  if(currentNode -> left != NULL){
   currentNode = currentNode -> left;
   printf("L:%d\n",currentNode->val);
  }
  printf("------------------------\n");
 //}
}

int main(void){
 node *first = newNode(0,6);
 node *rightNode = newNode(1,8);
 node *leftNode = newNode(0,5);
 MoveUp();
 node *rightLeftNode = newNode(1,12);
 printTree();
 free(first);
 free(rightNode);
 free(leftNode);
}