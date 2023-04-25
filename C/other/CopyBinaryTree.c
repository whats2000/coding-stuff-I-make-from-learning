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

void copy_tree(TreeNode* root1, TreeNode** root2) {
    if (root1 == NULL) {
        *root2 = NULL;
        return;
    }

    *root2 = (TreeNode*)malloc(sizeof(TreeNode));
    (*root2)->data = root1->data;

    copy_tree(root1->left_child, &((*root2)->left_child));
    copy_tree(root1->right_child, &((*root2)->right_child));
}

void inorder_print(TreeNode* root) {
    if (root) {
        inorder_print(root->left_child);
        printf("%d ", root->data);
        inorder_print(root->right_child);
    }
}

int main() {
    TreeNode* root_a = NULL;
    TreeNode* root_b = NULL;

    add_node(&root_a, 5);
    add_node(&root_a, 2);
    add_node(&root_a, 7);
    add_node(&root_a, 1);
    add_node(&root_a, 3);
    add_node(&root_a, 6);
    add_node(&root_a, 8);

    /* 現在二元樹的結構為：
    //          5
    //        /   \
    //       2     7
    //      / \   / \
    //     1   3 6   8   */

    inorder_print(root_a);
    printf("\n");

    copy_tree(root_a, &root_b);

    /* 現在二元樹的結構為：
    //          5
    //        /   \
    //       2     7
    //      / \   / \
    //     1   3 6   8   */

    inorder_print(root_b);

    return 0;
}
