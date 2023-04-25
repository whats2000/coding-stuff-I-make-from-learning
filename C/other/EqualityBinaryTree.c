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

int compare_trees(TreeNode* root1, TreeNode* root2) {
    if (root1 == NULL && root2 == NULL) {
        return 1;
    } else if (root1 == NULL || root2 == NULL) {
        return 0;
    } else if (root1->data != root2->data) {
        return 0;
    } else {
        int left_same = compare_trees(root1->left_child, root2->left_child);
        int right_same = compare_trees(root1->right_child, root2->right_child);

        return left_same && right_same;
    }
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
    TreeNode* root_c = NULL;

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
    printf("\n");

    add_node(&root_c, 4);
    add_node(&root_c, 2);
    add_node(&root_c, 6);
    add_node(&root_c, 1);
    add_node(&root_c, 3);
    add_node(&root_c, 5);
    add_node(&root_c, 7);

    /* 現在二元樹的結構為：
//          4
//        /   \
//       2     6
//      / \   / \
//     1   3 5   7   */

    inorder_print(root_c);
    printf("\n");

    printf("The A B trees are%sidentical.\n",
           compare_trees(root_a, root_b) ? " " : " not ");
    printf("The A C trees are%sidentical.\n",
           compare_trees(root_a, root_c) ? " " : " not ");

    return 0;
}
