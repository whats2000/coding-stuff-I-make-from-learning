#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left_child, *right_child;
} TreeNode;

void add_node(TreeNode** root, int data) {
    if (*root == NULL) {
        // 樹為空，建立新節點
        *root = (TreeNode*)malloc(sizeof(TreeNode));
        (*root)->data = data;
        (*root)->left_child = NULL;
        (*root)->right_child = NULL;
    } else {
        if (data < (*root)->data) {
            // 新值小於節點值，往左子樹遞迴
            add_node(&((*root)->left_child), data);
        } else {
            // 新值大於等於節點值，往右子樹遞迴
            add_node(&((*root)->right_child), data);
        }
    }
}

void inorder_print(TreeNode* root) {
    if (root) {
        inorder_print(root->left_child);
        printf("%d ", root->data);
        inorder_print(root->right_child);
    }
}

void preorder_print(TreeNode* root) {
    if (root) {
        printf("%d ", root->data);
        preorder_print(root->left_child);
        preorder_print(root->right_child);
    }
}

void postorder_print(TreeNode* root) {
    if (root) {
        postorder_print(root->left_child);
        postorder_print(root->right_child);
        printf("%d ", root->data);
    }
}

int main() {
    TreeNode* root = NULL;

    add_node(&root, 5);
    add_node(&root, 2);
    add_node(&root, 7);
    add_node(&root, 1);
    add_node(&root, 3);
    add_node(&root, 6);
    add_node(&root, 8);

    /* 現在二元樹的結構為：
    //          5
    //        /   \
    //       2     7
    //      / \   / \
    //     1   3 6   8   */

    inorder_print(root);
    printf("\n");
    preorder_print(root);
    printf("\n");
    postorder_print(root);

    return 0;
}
