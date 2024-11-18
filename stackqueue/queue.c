#include <stdio.h>

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
// enqueue
Node *enqueue(Node *head, char v)
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
// dequeue
char dequeue(Node **head)
{
      if (*head == NULL)
            return NULL;
      Node *p, *q;
      p = *head;
      char ans;

      // neu hang doi chi co 1 phan tu
      if (p->next == NULL)
      {
            ans = p->value;
            free(p);
            *head = NULL;
            return ans;
      }
      // Neu hang doi co nhieu hon mot phan tu, lay phan tu cuoi cung cua danh sach
      while (p->next->next != NULL)
      {
            p = p->next;
      }
      q = p->next;
      p->next = NULL;
      ans = q->value;
      free(q);
      return ans;
}
void printQueue(Node *head)
{
      if (head == NULL)
      {
            printf("Queue is empty\n");
            return;
      }

      Node *temp = head;
      while (temp != NULL)
      {
            printf("%c -> ", temp->value);
            temp = temp->next;
      }
      printf("NULL\n");
}

int main()
{
      Node *queue = NULL;

      // Thêm phần tử vào hàng đợi
      queue = enqueue(queue, 'A');
      queue = enqueue(queue, 'B');
      queue = enqueue(queue, 'C');

      // In ra hàng đợi
      printf("Queue: ");
      printQueue(queue);

      // Xóa phần tử khỏi hàng đợi
      dequeue(&queue);

      // In ra hàng đợi sau khi dequeue
      printf("Queue after dequeue: ");
      printQueue(queue);

      return 0;
}