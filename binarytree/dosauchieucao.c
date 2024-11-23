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

// Thêm nút vào cây nhị phân
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

// Tính chiều cao của cây
int findHeight(struct Node *node)
{
      if (node == NULL)
            return -1; // Chiều cao của cây rỗng là -1 (số cạnh)
      else
      {
            int leftHeight = findHeight(node->left);
            int rightHeight = findHeight(node->right);

            return (leftHeight > rightHeight ? leftHeight : rightHeight) + 1;
      }
}

// Tìm độ sâu của một nút trong cây
int findDepth(struct Node *root, struct Node *target, int depth)
{
      if (root == NULL)
            return -1; // Nếu không tìm thấy nút, trả về -1

      if (root == target)
            return depth; // Đã tìm thấy nút mục tiêu, trả về độ sâu hiện tại

      // Tìm trong cây con bên trái
      int leftDepth = findDepth(root->left, target, depth + 1);
      if (leftDepth != -1)
            return leftDepth;

      // Tìm trong cây con bên phải
      return findDepth(root->right, target, depth + 1);
}

int main()
{
      struct Node *root = NULL;
      root = insert(root, 50);
      struct Node *node30 = insert(root, 30);
      insert(root, 20);
      insert(root, 40);
      insert(root, 70);
      insert(root, 60);
      insert(root, 80);

      printf("Chiều cao của cây: %d\n", findHeight(root));

      int depth = findDepth(root, node30, 0);
      if (depth != -1)
            printf("Độ sâu của nút có giá trị 30: %d\n", depth);
      else
            printf("Nút không tồn tại trong cây.\n");

      return 0;
}
