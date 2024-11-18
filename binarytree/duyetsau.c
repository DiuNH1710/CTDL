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

// Hàm duyệt cây theo thứ tự sau
void postorder(struct TreeNode *root)
{
      if (root == NULL)
            return;

      // Duyệt cây con trái
      postorder(root->left);
      // Duyệt cây con phải
      postorder(root->right);
      // Thăm nút gốc
      printf("%c ", root->value);
}

int main()
{
      // Tạo cây ví dụ
      struct TreeNode *root = createNode('A');
      root->left = createNode('B');
      root->right = createNode('C');
      root->left->left = createNode('D');
      root->left->right = createNode('E');
      root->right->right = createNode('F');

      printf("Kết quả duyệt sau: ");
      postorder(root); // D E B F C A
      return 0;
}
