#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

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

int main() {
    GraphNode* graph[MAX_VERTICES] = {NULL};
    int vertex_in_use = 0;

    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 1);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 5, 6);
    add_edge(graph, 6, 7);
    add_edge(graph, 7, 5);
    /*
    1 --- 2
    |\   /|
    | \ / |
    |  3  |
    | / \ |
    |/   \|
    4 --- 5 --- 6
          |     |
          |     |
          7 ----

    */
    vertex_in_use = 7;
    print_graph(graph, vertex_in_use);
    return 0;
}