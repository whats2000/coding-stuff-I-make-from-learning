#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// TO-DO: implement postorder traversal.
void postorder(Node* root) {
    // write your code.
    if (root) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int preindex = 0;  // record index of preorder[]

// TO-DO: construct a binary tree from inoder and preorder traversal.
Node* build_binary_tree(int inorder[], int preorder[], int instart, int inend) {
    // write your code.
    // 當遞迴 instart 大於 inend 終止
    if (instart > inend)
        return NULL;

    // 找尋當前分支起點值在 inorder 位置
    int inorder_index = 0;
    for (inorder_index = instart; inorder_index <= inend; inorder_index++)
        if (inorder[inorder_index] == preorder[preindex])
            break;

    // 新節點
    Node* root = (Node*)malloc(sizeof(Node));

    root->data = preorder[preindex];
    root->left = NULL;
    root->right = NULL;

    preindex++;

    root->left =
        build_binary_tree(inorder, preorder, instart, inorder_index - 1);
    root->right =
        build_binary_tree(inorder, preorder, inorder_index + 1, inend);

    return root;
}

int main() {
    int tree1inorder[] = {1, 2, 3, 4, 5, 6, 7};
    int tree1preorder[] = {4, 2, 1, 3, 6, 5, 7};
    int len1 = sizeof(tree1inorder) / sizeof(tree1inorder[0]);
    Node* root1 = build_binary_tree(tree1inorder, tree1preorder, 0, len1 - 1);
    printf("tree1 preorder traversal: 4, 2, 1, 3, 6, 5, 7 \n");
    printf("tree1 inorder traversal: 1, 2, 3, 4, 5, 6, 7 \n");
    printf("tree1 postorder traversal: ");
    postorder(root1);
    preindex = 0;

    printf("\n");
    int tree2inorder[] = {5, 9, 3, 8, 4, 7, 6};
    int tree2preorder[] = {8, 9, 5, 3, 7, 4, 6};
    int len2 = sizeof(tree2inorder) / sizeof(tree2inorder[0]);
    Node* root2 = build_binary_tree(tree2inorder, tree2preorder, 0, len2 - 1);
    printf("nntree2 preorder traversal: 5, 9, 3, 8, 4, 7, 6 \n");
    printf("tree2 inorder traversal: 8, 9, 5, 3, 7, 4, 6 \n");
    printf("tree2 postorder traversal: ");
    postorder(root2);
    preindex = 0;

    return 0;
}
