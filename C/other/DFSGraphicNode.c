#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

short int visited[MAX_VERTICES];

typedef struct node {
    int vertex;
    struct node* link;
} GraphNode;

void add_edge(GraphNode** graph, int u, int v) {
    // 增加正向邊
    GraphNode* new_node = (GraphNode*)malloc(sizeof(GraphNode));
    new_node->vertex = v;
    new_node->link = graph[u];
    graph[u] = new_node;

    // 增加反向邊
    GraphNode* reverse_node = (GraphNode*)malloc(sizeof(GraphNode));
    reverse_node->vertex = u;
    reverse_node->link = graph[v];
    graph[v] = reverse_node;
}

void print_graph(GraphNode** graph, int vertex_in_use) {
    for (int i = 0; i < vertex_in_use; i++) {
        printf("Vertex %d: ", i);
        GraphNode* current_node = graph[i];
        while (current_node != NULL) {
            printf("%d ", current_node->vertex);
            current_node = current_node->link;
        }
        printf("\n");
    }
}

void depth_first_search(GraphNode** graph, int v) {
    GraphNode* w;
    visited[v] = 1;
    printf("%5d", v);
    for (w = graph[v]; w; w = w->link) {
        if (!visited[w->vertex]) {
            depth_first_search(graph, w->vertex);
        }
    }
}

int main() {
    GraphNode* graph[MAX_VERTICES] = {NULL};
    int vertex_in_use = 0;

    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 0, 7);

    add_edge(graph, 1, 2);

    add_edge(graph, 2, 7);
    add_edge(graph, 2, 3);

    add_edge(graph, 3, 4);
    add_edge(graph, 3, 5);
    add_edge(graph, 3, 7);

    add_edge(graph, 4, 5);

    add_edge(graph, 5, 6);

    add_edge(graph, 6, 7);
    /*
    1 ----
    |     |
    |     |
    0 --- 2
    |    /|
    |   / |
    |  /  |
    | /   |
    |/    |
    7 --- 3 ---
    |     |     |
    |     |     |
    6 --- 5 --- 4

    */
    vertex_in_use = 8;

    print_graph(graph, vertex_in_use);

    printf("DFS Traversal starting from vertex 1: ");
    depth_first_search(graph, 1);
    printf("\n");

    return 0;
}