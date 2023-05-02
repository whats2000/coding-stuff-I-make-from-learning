#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 50

typedef struct node {
    int vertex;
    int weight;
    struct node* link;
} GraphNode;

void add_edge(GraphNode** graph, int u, int v, int weight) {
    // 增加正向邊
    GraphNode* new_node = (GraphNode*)malloc(sizeof(GraphNode));
    new_node->vertex = v;
    new_node->weight = weight;
    new_node->link = graph[u];
    graph[u] = new_node;

    // 增加反向邊
    GraphNode* reverse_node = (GraphNode*)malloc(sizeof(GraphNode));
    reverse_node->vertex = u;
    reverse_node->weight = weight;
    reverse_node->link = graph[v];
    graph[v] = reverse_node;
}

void print_graph(GraphNode** graph, int vertex_in_use) {
    for (int i = 0; i < vertex_in_use; i++) {
        printf("Vertex %d: ", i);
        GraphNode* current_node = graph[i];
        while (current_node != NULL) {
            printf("(%d, %d) ", current_node->vertex, current_node->weight);
            current_node = current_node->link;
        }
        printf("\n");
    }
}

int main() {
    GraphNode* graph[MAX_VERTICES] = {NULL};
    int vertex_in_use = 0;

    add_edge(graph, 0, 1, 16);
    add_edge(graph, 0, 2, 13);
    add_edge(graph, 0, 7, 27);

    add_edge(graph, 1, 2, 11);

    add_edge(graph, 2, 3, 20);
    add_edge(graph, 2, 7, 6);

    add_edge(graph, 3, 4, 9);
    add_edge(graph, 3, 5, 18);
    add_edge(graph, 3, 7, 19);

    add_edge(graph, 4, 5, 14);

    add_edge(graph, 5, 6, 26);

    add_edge(graph, 6, 7, 10);
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
    return 0;
}