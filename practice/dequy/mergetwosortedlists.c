#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
      int value;
      struct Node *next;
} Node;

Node *makeNode(int v)
{
      Node *p = (Node *)malloc(sizeof(Node));
      p->value = v;
      p->next = NULL;
      return p;
}

void printList(Node *h)
{
      Node *p = h;
      while (p != NULL)
      {
            printf("%d ", p->value);
            p = p->next;
      }
      printf("\n");
}

Node *inputList()
{
      int n, value;
      Node *head, *tail;
      head = NULL;
      tail = NULL;
      printf("nhap n = ");
      scanf("%d", &n);
      if (n <= 0)
            return NULL;
      printf("nhap cac phan tu");
      for (int i = 0; i < n; i++)
      {
            scanf("%d", &value);
            Node *newNode = makeNode(value);
            if (head == NULL)
            {
                  head = newNode;
                  tail = newNode;
            }
            else
            {
                  tail->next = newNode;
                  tail = newNode;
            }
      }
      return head;
}

Node *mergeList(Node *list1, Node *list2)
{
      if (list1 == NULL)
            return list2;
      if (list2 == NULL)
            return list1;

      // khoi tao con tro dau va cuoi cho list hop nhat
      Node *head = NULL;
      Node *tail = NULL;

      // xac dinh phan tu dau tien cua danh sach hop nhat
      if (list1->value < list2->value)
      {
            head = tail = list1;
            list1 = list1->next;
      }
      else
      {
            head = tail = list2;
            list2 = list2->next;
      }
      // hop nhat 2 danh sach con lai

      while (list1 != NULL && list2 != NULL)
      {
            if (list1->value < list2->value)
            {
                  tail->next = list1;
                  list1 = list1->next;
            }
            else
            {
                  tail->next = list2;
                  list2 = list2->next;
            }
            tail = tail->next;
      }
      if (list1 != NULL)
      {
            tail->next = list1;
      }
      else
      {
            tail->next = list2;
      }
      return head;
}

int main()
{
      printf("nhap danh sach 1");
      Node *list1 = inputList();
      printf("nhap danh sach 2");
      Node *list2 = inputList();
      Node *merge = mergeList(list1, list2);
      printList(merge);
      return 0;
}