#include<stdio.h>
#include<stdlib.h>


typedef struct Node
{
      int v;
      struct Node* next;
}Node;

Node *makeNode(int value){
      Node* node = (Node*)malloc(sizeof(Node));
      node -> v = value;
      node -> next = NULL;
      return node; 
}
Node* find (int value, Node* head ){
      Node* p = head;
      while ( p!= NULL)
      {
            if(p->v == value){
                  printf("Found!");
                  return p;
            } else {
                  p= p->next;

            }
      }
      printf ("Not Found!");
      return NULL;
      

}
Node* insertFirst(Node* head, int v){
      Node* newNode = makeNode(v);
      if(head ==NULL) return newNode;
      newNode ->next = head;
      head = newNode;
      return head; 
}

Node* insertLast(Node* head, int v){
      Node* newNode = makeNode(v);
      
      if(head ==NULL) return newNode;
      Node* p = head;

      while (p -> next != NULL) {
          
            p = p -> next ;
      }
      p -> next = newNode; 

      return head; 
}

Node* insertBeforeNode(Node* head,Node*p, int v){
      Node* prev = findPrev(head, p ); 
      if (prev==NULL && p!=NULL);
      Node* newNode = makeNode(v);
      newNode->next = p; 
      prev->next = newNode;
      return head; 
      

     
}

void printList (Node* head){
      Node* p = head;
      while(p!=NULL){
            printf("%d", p->v);
            p = p -> next;
      }
}

int main( ){
      Node* head, *node1, *node2, *node3; 
      head = makeNode(1);
      node1= makeNode(2);
      node2 = makeNode(3);
      node3 = makeNode(4);
      head -> next = node1;
      node1-> next = node2;
      node2-> next = node3;

      Node* res = find(5, head);
      head = insertFirst(head,5);
      printList(head); 
      head = insertLast (head, 6); 

      printList(head);
      head = insertBeforeNode(head, head->next, 7); 
      printList(head);

return 0;
}
