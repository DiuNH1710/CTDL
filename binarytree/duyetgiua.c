#include <stdio.h>
#include <stdlib.h>

// Định nghĩa cấu trúc cây
struct TreeNode
{
      char value;
      struct TreeNode *left, *right;
};

// Tạo một nút mới
struct TreeNode *createNode(char value)
{
      struct TreeNode *node = (struct TreeNode *)malloc(sizeof(struct TreeNode));
      node->value = value;
      node->left = node->right = NULL;
      return node;
}

// Hàm duyệt cây theo thứ tự giữa
void inorder(struct TreeNode *root)
{
      if (root == NULL)
            return;

      // Duyệt cây con trái
      inorder(root->left);
      // Thăm nút gốc
      printf("%c ", root->value);
      // Duyệt cây con phải
      inorder(root->right);
}

int main()
{
      // Tạo cây ví dụ
      struct TreeNode *root = createNode('A');
      root->left = createNode('B');
      root->right = createNode('C');
      root->left->left = createNode('D');
      root->left->right = createNode('E');
      root->right->left = createNode('F'); // Cây con trái của C

      printf("Kết quả duyệt giữa: ");
      inorder(root); // D B E A F C
      return 0;
}
