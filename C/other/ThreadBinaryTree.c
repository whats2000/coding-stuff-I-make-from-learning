#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    char data;

    struct node* left_child;
    struct node* right_child;

    short int left_thread;
    short int right_thread;
} ThreadedTree;

ThreadedTree* create_node(char data) {
    ThreadedTree* new_node = (ThreadedTree*)malloc(sizeof(ThreadedTree));
    new_node->data = data;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    new_node->left_thread = 0;
    new_node->right_thread = 0;
    return new_node;
}

void insert_left_child(ThreadedTree* parent, ThreadedTree* child) {
    child->left_child = parent->left_child;
    child->left_thread = parent->left_thread;
    child->right_child = parent;
    child->right_thread = 1;
    parent->left_child = child;
    parent->left_thread = 0;
}

void insert_right_child(ThreadedTree* parent, ThreadedTree* child) {
    child->right_child = parent->right_child;
    child->right_thread = parent->right_thread;
    child->left_child = parent;
    child->left_thread = 1;
    parent->right_child = child;
    parent->right_thread = 0;
}

ThreadedTree* search_node(ThreadedTree* root, char data) {
    if (root == NULL || root->data == data) {
        return root;
    }
    if (root->left_thread == 0 && root->left_child != NULL) {
        ThreadedTree* left_node = search_node(root->left_child, data);
        if (left_node != NULL) {
            return left_node;
        }
    }
    if (root->right_thread == 0 && root->right_child != NULL) {
        ThreadedTree* right_node = search_node(root->right_child, data);
        if (right_node != NULL) {
            return right_node;
        }
    }
    return NULL;
}

void inorder_traversal(ThreadedTree* root) {
    ThreadedTree* node = root;
    while (node->left_thread == 0) {
        node = node->left_child;
    }
    while (node != NULL) {
        printf("%c ", node->data);
        if (node->right_thread == 1) {
            node = node->right_child;
        } else {
            node = node->right_child;
            while (node->left_thread == 0) {
                node = node->left_child;
            }
        }
    }
}

int main() {
    ThreadedTree* root = create_node('A');
    ThreadedTree* node1 = create_node('B');
    ThreadedTree* node2 = create_node('C');
    ThreadedTree* node3 = create_node('D');
    ThreadedTree* node4 = create_node('E');

    insert_left_child(root, node1);
    insert_right_child(root, node2);
    insert_left_child(node1, node3);
    insert_right_child(node2, node4);

    printf("Inorder Traversal: ");
    inorder_traversal(root);
    printf("\n");

    return 0;
}
