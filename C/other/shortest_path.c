#include <stdio.h>
#define MAX_ERXTICES 8
#define FALSE 0
#define TRUE 1
#define INT_MAX 9999999

void shortestpath(int v,
                  int cost[][MAX_ERXTICES],
                  int distance[],
                  int n,
                  short int found[]);
int choose(int distance[], int n, short int found[]);

void main() {
    // Adjacency Matrix                0        1        2        3        4 5
    // 6        7
    int cost[][MAX_ERXTICES] = {
        {0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX,
         INT_MAX},                                                        // 0
        {300, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},   // 1
        {600, 100, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX},       // 2
        {INT_MAX, INT_MAX, 120, 0, INT_MAX, INT_MAX, INT_MAX, INT_MAX},   // 3
        {INT_MAX, INT_MAX, INT_MAX, 1500, 0, 150, INT_MAX, INT_MAX},      // 4
        {INT_MAX, INT_MAX, INT_MAX, 900, INT_MAX, 0, 700, 1400},          // 5
        {INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0, 100},   // 6
        {170, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, INT_MAX, 0}};  // 7

    int n = MAX_ERXTICES;           // Number of nodes.
    int v = 4;                      // Starting vertex.
    int distance[MAX_ERXTICES];     // record the shortest distance.
    short int found[MAX_ERXTICES];  // record the node visited.

    shortestpath(v, cost, distance, n, found);
}

void print_path_to_v(int v, int last_path_to[]) {
    // 如果沒有變更路徑代表到達起點，終止遞迴
    if (last_path_to[v] == -1) {
        printf("4");
        return;
    }

    // 否，則輸出當前位置，並找尋當前位值的前個最後變更位置
    printf("%d <- ", last_path_to[v]);
    print_path_to_v(last_path_to[v], last_path_to);
}

void shortestpath(int v,
                  int cost[][MAX_ERXTICES],
                  int distance[],
                  int n,
                  short int found[]) {
    int i, u, w;
    for (i = 0; i < n; i++) {
        found[i] = FALSE;
        distance[i] = cost[v][i];
    }

    found[v] = TRUE;
    distance[v] = 0;
    /*-------------------------------------------------
    Hint: Declare the array of shortest path.
    Hint: Using For-loop to set the array.
    Finish your code below.
    ---------------------------------------------------*/
    int last_path_to[MAX_ERXTICES] = {0};

    for (int i = 0; i < n; i++) {
        last_path_to[i] = -1;
    }

    int node;

    for (i = 0; i < n - 2; i++) {
        u = choose(distance, n, found);
        found[u] = TRUE;
        for (w = 0; w < n; w++) {
            if (distance[u] + cost[u][w] < distance[w]) {
                distance[w] = distance[u] + cost[u][w];
                /*-----------------------------------------
                Hint: Record the shortest path.
                Finish your code below.
                -------------------------------------------*/
                // 紀錄最後變更的路徑
                last_path_to[w] = u;
            }
        }
    }
    printf("Vertex %d to all shortest distances: ", v);
    for (i = 0; i < MAX_ERXTICES; i++)
        printf("%d ", distance[i]);
    printf("\n");
    /*-------------------------------------------------
    Hint: Using For-loop to print the path.
    Finish your code below.
    ---------------------------------------------------*/
    // 輸出起時點並遞迴前面變更位置，最後輸出花費
    for (int i = 0; i < n; i++) {
        printf("%d <- ", i);
        print_path_to_v(i, last_path_to);
        printf(" %d\n", distance[i]);
    }
}

int choose(int distance[], int n, short int found[]) {
    int i, min, minpos;
    min = INT_MAX;
    minpos = -1;
    for (i = 0; i < n; i++) {
        if (distance[i] < min && !found[i]) {
            min = distance[i];
            minpos = i;
        }
    }
    return minpos;
}
