#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *left, *right;
} Node;

// TO-DO: implement inorder traversal.
void inorder(Node* root) {
    // write your code.
    if (root) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

// TO-DO: count the number of non-leaf in a binary search tree.
int countnonleaf(Node* node) {
    // write your code.
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 0;
    else if (node->right == NULL)
        return countnonleaf(node->left) + 1;
    else if (node->left == NULL)
        return countnonleaf(node->right) + 1;
    else
        return countnonleaf(node->left) + countnonleaf(node->right) + 1;
}

// TO-DO: count the number of leaf in a binary search tree.
int countleaf(Node* node) {
    // write your code.
    if (node == NULL)
        return 0;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else if (node->right == NULL)
        return countleaf(node->left);
    else if (node->left == NULL)
        return countleaf(node->right);
    else
        return countleaf(node->left) + countleaf(node->right);
}

// TO-DO: calculate the height of the binary search tree.
int height(Node* node) {
    // write your code.
    if (node == NULL)
        return 0;
    else
        return (height(node->left) > height(node->right)
                    ? height(node->left)
                    : height(node->right)) +
               1;
}

// TO-DO: check if this tree is a binary search tree.
int is_BST(Node* node) {
    // write your code.
    if (node == NULL)
        return 1;
    else if (node->left == NULL && node->right == NULL)
        return 1;
    else if (node->right == NULL)
        return is_BST(node->left);
    else if (node->left == NULL)
        return is_BST(node->right);
    else
        return ((node->left->data < node->data) &&
                (node->right->data > node->data)) &&
               is_BST(node->left) && is_BST(node->right);
}

// TO-DO: insert a node in a binary search tree.
Node* insert(Node* node, int data) {
    // write your code.
    // 樹為空，建立新節點
    if (node == NULL) {
        node = (Node*)malloc(sizeof(Node));
        node->data = data;
        node->left = NULL;
        node->right = NULL;

        return node;
    } else {
        // 新值小於節點值，往左子樹遞迴
        if (data < node->data)
            node->left = insert(node->left, data);
        // 新值大於等於節點值，往右子樹遞迴
        else
            node->right = insert(node->right, data);
    }
}

int main() {
    int insert_data[] = {8, 4, 12, 2, 6, 10, 14, 1, 3, 5, 7, 9, 11, 13, 15};
    Node* root = NULL;
    int i;
    root = insert(root, insert_data[0]);
    int len = sizeof(insert_data) / sizeof(insert_data[0]);
    for (i = 1; i < len; i++) {
        insert(root, insert_data[i]);
    }
    printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root) == 1 ? "Yes" : "No");
    printf("\nroot data: %d\n", root->data);
    printf("the number of leaves: %d\n", countleaf(root));
    printf("the number of non-leaves: %d\n", countnonleaf(root));
    printf("height: %d\n\n", height(root));

    root->data = 20;
    printf("Modify Binary Search Tree(BST): \n");
    printf("inorder traversal: ");
    inorder(root);
    printf("\nIs it a Binary Search Tree(BST)?: ");
    printf(is_BST(root) == 1 ? "Yes" : "No");
    return 0;
}
