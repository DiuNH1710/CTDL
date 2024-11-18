#include <stdio.h>

typedef struct Node
{
      int value;
      struct Node *next;
} Node;
// Tao 1 node moi
Node *makeNode(int v)
{
      Node *p = (Node *)malloc(sizeof(Node));
      p->value = v;
      p->next = NULL;
      return p;
}
// Print a list
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

// find node with given value
Node *findFirst(Node *head, int val)
{
      Node *p = head;
      while (p != NULL)
      {
            if (p->value == val)
            {
                  return p;
            }
            p = p->next;
      }

      return NULL;
}
// insert first

Node *insertFirst(Node *head, int v)
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
// insert last : find last node -> insert last

Node *findLastNode(Node *head)
{
      Node *p = head;
      while (p != NULL)
      {
            if (p->next == NULL)
                  return p;
            p = p->next;
      }
      return NULL;
}

Node *insertLast(Node *head, int v)
{
      Node *newNode = makeNode(v);
      if (head == NULL)
            return newNode;
      else
      {
            Node *lastNode = findLastNode(head);
            lastNode->next = newNode;
            return head;
      }
}

// insert before node: tim phan tu dung truoc -> thuc hien chen
Node *prevNode(Node *head, Node *p)
{
      Node *q = head;
      while (q != NULL)
      {
            if (q->next == p)
                  return q;
            q = q->next;
      }
      return NULL;
}

Node *insertBeforeNode(Node *head, Node *p, int v)
{

      if (p == NULL)
      {
            return head;
      }
      Node *pp = prevNode(head, p);
      Node *q = makeNode(v);
      if (pp == NULL)
      {
            if (head == NULL)
                  return q;
            q->next = head;
            return q;
      }
      q->next = p;
      pp->next = q;
      return head;
}

// xoa mot phan tu ra khoi danh sach lien ket
Node *removeNode(Node *head, Node *p)
{
      if (head == NULL || p == NULL)
            return head;
      if (head == p)
      {
            head = head->next;
            free(p);
            return head;
      }
      else
      {
            head->next = removeNode(head->next, p);
            return head;
      }
}

// remove node không dùng đẹ quy
Node *removeNode1(Node *head, Node *p)
{
      if (head == NULL || p == NULL) // Nếu danh sách rỗng hoặc node p là NULL
            return head;

      if (head == p) // Nếu node cần xóa là head
      {
            head = head->next;
            free(p);
            return head;
      }

      Node *current = head;
      while (current->next != NULL && current->next != p) // Tìm node trước p
      {
            current = current->next;
      }

      if (current->next == p) // Nếu tìm thấy p
      {
            current->next = p->next; // Bỏ qua node p
            free(p);                 // Giải phóng bộ nhớ
      }
      return head; // Trả về head ban đầu
}

// đảo ngược thứ tự các phần tử của danh sách liên kết

Node *reverse(Node *head)
{
      Node *cur = head;
      Node *next, *pre;
      pre = NULL;
      next = NULL;
      while (cur != NULL)
      {
            next = cur->next;
            cur->next = pre;
            pre = cur;
            cur = next;
      }
      head = pre;
      return (head);
}

// Dung de qui de dao nguoc danh sach
Node *reverse1(Node *head)
{
      // Điều kiện dừng: nếu head là NULL hoặc là node cuối cùng
      if (head == NULL || head->next == NULL)
      {
            return head;
      }

      // Đệ quy đảo ngược phần còn lại của danh sách
      Node *newHead = reverse1(head->next);

      // Đảo ngược liên kết của node tiếp theo
      head->next->next = head;
      head->next = NULL;

      return newHead;
}

int main()
{
      int *pc, c;
      c = 22;
      printf("Address of c: %p\n", &c); // dia chi cua c trong bo nho, %p: dang so hexadecimal
      printf("Address of c: %d\n", c);

      Node *head, *node1, *node2;
      head = makeNode(10);
      node1 = makeNode(20);
      node2 = makeNode(30);

      head->next = node1;
      node1->next = node2;
      printList(head);
      // find a node
      Node *res = findFirst(head, 20);
      if (res != NULL)
      {
            printf("Found \n");
      }
      else
      {
            printf("Not Found \n");
      }

      head = insertFirst(head, 5);
      printList(head);

      head = insertLast(head, 40);
      printList(head);

      Node *nodeInsert = findFirst(head, 20);
      head = insertBeforeNode(head, nodeInsert, 35);
      printList(head);

      Node *nodeRemove = findFirst(head, 40);
      head = removeNode(head, nodeRemove);
      printList(head);

      Node *nodeRemove1 = findFirst(head, 60);
      head = removeNode1(head, nodeRemove1);
      printList(head);

      head = reverse(head);
      printList(head);

      head = reverse1(head);
      printList(head);

      return 0;
}