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
      Node *newNode = (Node *)malloc(sizeof(Node));
      newNode->data = data;
      newNode->left = NULL;
      newNode->right = NULL;
      return newNode;
}

// Hàm đếm số lượng nút có 2 con
int countNodesWithTwoChildren(Node *root)
{
      if (root == NULL)
      {
            return 0; // Nếu cây rỗng, trả về 0
      }

      // Kiểm tra nếu nút hiện tại có cả hai con
      int count = 0;
      if (root->left != NULL && root->right != NULL)
      {
            count = 1;
      }

      // Đệ quy cho cây con bên trái và bên phải
      return count + countNodesWithTwoChildren(root->left) + countNodesWithTwoChildren(root->right);
}

int main()
{
      // Tạo cây nhị phân mẫu
      Node *root = createNode(1);
      root->left = createNode(2);
      root->right = createNode(3);
      root->left->left = createNode(4);
      root->left->right = createNode(5);
      root->right->right = createNode(6);

      // Đếm số lượng nút có 2 con
      int count = countNodesWithTwoChildren(root);
      printf("So luong nut co 2 con la: %d\n", count);

      return 0;
}
