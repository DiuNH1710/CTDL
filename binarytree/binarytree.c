#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc của một nút trong cây nhị phân
struct Node
{
      int data;
      struct Node *left;
      struct Node *right;
};

// Hàm tạo một nút mới
struct Node *createNode(int data)
{
      struct Node *node = (struct Node *)malloc(sizeof(struct Node));
      node->data = data;
      node->left = NULL;
      node->right = NULL;
      return node;
}

// Thêm nút vào cây nhị phân (theo thứ tự nhị phân tìm kiếm)
struct Node *insert(struct Node *node, int data)
{
      if (node == NULL)
            return createNode(data);

      if (data < node->data)
            node->left = insert(node->left, data);
      else if (data > node->data)
            node->right = insert(node->right, data);

      return node;
}

// Duyệt cây theo thứ tự trước (Preorder)
void preorder(struct Node *root)
{
      if (root != NULL)
      {
            printf("%d ", root->data);
            preorder(root->left);
            preorder(root->right);
      }
}

// Duyệt cây theo thứ tự giữa (Inorder)
void inorder(struct Node *root)
{
      if (root != NULL)
      {
            inorder(root->left);
            printf("%d ", root->data);
            inorder(root->right);
      }
}

// Duyệt cây theo thứ tự sau (Postorder)
void postorder(struct Node *root)
{
      if (root != NULL)
      {
            postorder(root->left);
            postorder(root->right);
            printf("%d ", root->data);
      }
}

int main()
{
      struct Node *root = NULL;
      root = insert(root, 50);
      insert(root, 30);
      insert(root, 20);
      insert(root, 40);
      insert(root, 70);
      insert(root, 60);
      insert(root, 80);

      printf("Duyệt cây theo thứ tự giữa (Inorder): ");
      inorder(root);
      printf("\n");

      printf("Duyệt cây theo thứ tự trước (Preorder): ");
      preorder(root);
      printf("\n");

      printf("Duyệt cây theo thứ tự sau (Postorder): ");
      postorder(root);
      printf("\n");

      return 0;
}
