#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100

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

// Hàm duyệt cây theo thứ tự trước (không đệ quy)
void preorderIterative(struct TreeNode *root)
{
      if (root == NULL)
            return;

      struct TreeNode *stack[MAX_STACK_SIZE];
      int top = -1;

      stack[++top] = root;

      while (top != -1)
      {
            struct TreeNode *current = stack[top--];

            // Thăm nút hiện tại
            printf("%c ", current->value);

            // Đẩy cây con phải vào stack trước (để cây con trái được duyệt trước)
            if (current->right != NULL)
                  stack[++top] = current->right;
            if (current->left != NULL)
                  stack[++top] = current->left;
      }
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

      printf("Kết quả duyệt trước (không đệ quy): ");
      preorderIterative(root); // A B D E C F
      return 0;
}
