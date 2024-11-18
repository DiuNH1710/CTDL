#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
      int val;
      struct Node *next;
} Node;
// Tao 1 node moi
Node *makeNode(int v)
{
      Node *p = (Node *)malloc(sizeof(Node));
      p->val = v;
      p->next = NULL;
      return p;
}

Node *inputList()
{
      int n, val;
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
            scanf("%d", &val);
            Node *newNode = makeNode(val);
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

void printList(Node *h)
{
      if (h == NULL)
      {
            printf("Danh sách hiện tại trống.\n");
            return;
      }
      Node *p = h;
      while (p != NULL)
      {
            printf("%d ", p->val);
            p = p->next;
      }
      printf("\n");
}

Node *removeNode(Node *head, int val)
{
      if (head == NULL)
            return NULL;
      if (head->val == val)
      {
            Node *temp = head;
            head = head->next;
            free(temp);
            return removeNode(head, val);
      }

      head->next = removeNode(head->next, val);
      return head;
}

int main()
{
      Node *list1 = inputList();
      int i;
      printf("nhap gia tri muon xoa i = ");
      scanf("%d", &i);
      list1 = removeNode(list1, i);
      printf("Danh sách sau khi xóa: ");
      printList(list1);

      return 0;
}