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

void breadth_first_search(GraphNode** graph,
                          int start_vertex,
                          int vertex_in_use) {
    int queue[MAX_VERTICES];
    int front = 0, rear = 0;
    int visited[MAX_VERTICES] = {0};

    queue[rear++] = start_vertex;
    visited[start_vertex] = 1;

    while (front < rear) {
        int current_vertex = queue[front++];
        printf("%d ", current_vertex);

        GraphNode* current_node = graph[current_vertex];
        while (current_node != NULL) {
            int next_vertex = current_node->vertex;
            if (!visited[next_vertex]) {
                queue[rear++] = next_vertex;
                visited[next_vertex] = 1;
            }
            current_node = current_node->link;
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

    breadth_first_search(graph, 1, vertex_in_use);

    return 0;
}
