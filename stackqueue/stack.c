#include <stdio.h>
#include <stdbool.h> // thu vien de dung bool

typedef struct Node
{
      char value;
      struct Node *next;
} Node;

Node *makeNode(char v)
{
      Node *p = (Node *)malloc(sizeof(Node));
      p->value = v;
      p->next = NULL;
      return p;
}
// thao tac push
Node *push(Node *head, char v)
{
      Node *newNode = makeNode(v);
      if (head == NULL)
            return newNode;
      else
      {
            newNode->next = head;
            head = newNode;
            return head;
      }
}
// thao tac Pop
Node *pop(Node *head)
{
      if (head == NULL)
            return head;
      Node *p = head;
      head = head->next;
      free(p);
      return head;
}
// thao tac Top

char top(Node *head)
{
      return head->value;
}

// isEmpty
bool isEmpty(Node *head)
{
      if (head == NULL)
            return true;
      return (false);
}

// In stack
void printStack(Node *head)
{
      Node *p = head;
      if (p == NULL)
      {
            printf("Stack is empty.\n");
            return;
      }

      printf("Stack (top to bottom): ");
      while (p != NULL)
      {
            printf("%c ", p->value);
            p = p->next;
      }
      printf("\n");
}

int main()
{
      Node *head = NULL;

      // Push các giá trị vào stack
      head = push(head, 'A');
      head = push(head, 'B');
      head = push(head, 'C');

      // In stack
      printStack(head);

      // Pop một giá trị và in lại stack
      head = pop(head);
      printStack(head);

      // Lấy phần tử top của stack
      printf("Top element: %c\n", top(head));

      // Kiểm tra stack có rỗng không
      if (isEmpty(head))
      {
            printf("Stack is empty.\n");
      }
      else
      {
            printf("Stack is not empty.\n");
      }

      return 0;
}