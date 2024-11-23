#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
typedef struct Node
{
      int data;
      struct Node *left;
      struct Node *right;
} Node;

// Hàm tạo một nút mới
Node *createNode(int data)
{
      Node *node = (Node *)malloc(sizeof(struct Node));
      node->data = data;
      node->left = NULL;
      node->right = NULL;
      return node;
}
int height(Node *root)
{
      if (root == NULL)
      {
            return 0;
      }
      int leftHeight = height(root->left);
      int rightHeight = height(root->right);
      return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
}

int height2(Node *p)
{
      if (p == NULL)
            return 0;
      int maxh = 0;
      Node *q = p->left;
      while (q != NULL)
      {
            int h = height2(q);
            if (h > maxh)
                  maxh = h;
            q = q->right;
      }
      return maxh + 1;
}

int findDepth(Node *root, Node *target, int d)
{
      if (root == NULL)
      {
            return 0;
      }
      if (root == target)
      {
            return d;
      }
      // tim trong cay con trai
      int leftDepth = findDepth(root->left, target, d + 1);
      if (leftDepth != 0)
            return leftDepth;
      // Tim trong cay con phai
      return findDepth(root->right, target, d + 1);
}

int findDepth2(Node *r, int v, int d)
{
      if (r == NULL)
            return -1;
      if (r->data == v)
            return d;
      Node *p = r->left;
      while (p != NULL)
      {
            if (p->data == v)
                  return d + 1;
            int dv = findDepth2(p, v, d + 1);

            if (dv > 0)
                  return dv;

            p = p->right;
      }
      return -1;
}

// Hàm tính tổng của tất cả các nút lá
int tongNutLa(Node *root)
{
      if (root == NULL)
            return 0;

      // Nếu là nút lá (không có con trái và con phải)
      if (root->left == NULL && root->right == NULL)
            return root->data;

      // Nếu không phải là nút lá, tính tổng trong cây con trái và cây con phải
      return tongNutLa(root->left) + tongNutLa(root->right);
}
// dem cac nut la

int demNutLa(Node *root)
{
      if (root == NULL)
            return 0;

      // Nếu là nút lá (không có con trái và con phải)
      if (root->left == NULL && root->right == NULL)
            return 1;

      // Nếu không phải là nút lá, đếm trong cây con trái và cây con phải
      return demNutLa(root->left) + demNutLa(root->right);
}
int demNutLa3(Node *root)
{
      if (root == NULL)
            return 0;
      int count = (root->left == NULL && root->right == NULL) ? 1 : 0;
      return count + demNutLa3(root->left) + demNutLa3(root->right);
}
// Hàm đếm số lượng nút có 2 nút con
int demCacNutCo2NutCon(Node *root)
{
      if (root == NULL)
            return 0;

      // Kiểm tra xem nút có 2 con trái và phải không
      int count = (root->left != NULL && root->right != NULL) ? 1 : 0;

      // Đệ quy đếm trong cây con trái và cây con phải
      return count + demCacNutCo2NutCon(root->left) + demCacNutCo2NutCon(root->right);
}

int main()
{
      Node *root = createNode(7);
      root->left = createNode(3);
      root->left->left = createNode(8);
      root->left->right = createNode(12);
      root->right = createNode(4);
      root->right->left = createNode(11);
      root->right->right = createNode(2);
      root->left->left->left = createNode(6);
      root->left->left->right = createNode(5);
      root->left->left->right->left = createNode(9);
      printf("\n");
      printf("%d", height(root->left->left));
      printf("\n");
      printf("%d", height2(root->left->left));
      printf("\n");
      printf("%d", findDepth(root, root->left->left, 1));
      printf("\n");
      printf("%d", findDepth(root, root->left->left->right->left, 1));
      printf("\n");
      printf("%d", findDepth2(root, 8, 1));
      printf("\n");
      printf("%d", findDepth2(root, 9, 1));
      printf("\n");
      printf("tong cac nut la: %d", tongNutLa(root));
      printf("\n");
      printf("dem cac nut co 2 nut con : %d", demCacNutCo2NutCon(root));
      printf("\n");
      printf("dem cac nut la: %d", demNutLa(root));
      printf("\n");
      printf("dem cac nut la: %d", demNutLa3(root));
}