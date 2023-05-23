#include <stdio.h>

#define N 100

int Visited[N] = {0};

int hasCycle(int edges[][2], int numEdges) {
    int set = 1;
    for (int k = 0; k < numEdges; k++) {
        int i = edges[k][0];
        int j = edges[k][1];

        if (Visited[i] == 0 && Visited[j] == 0) {
            Visited[i] = Visited[j] = set;
            set++;
        } else if (Visited[i] == 0 || Visited[j] == 0) {
            int nonZero = (Visited[i] != 0) ? Visited[i] : Visited[j];
            Visited[i] = Visited[j] = nonZero;
        } else if (Visited[i] != Visited[j]) {
            int replace = Visited[j];
            int target = Visited[i];
            for (int m = 0; m < N; m++) {
                Visited[m] = (Visited[m] == target) ? replace : Visited[m];
            }
        } else {
            return 1;  // 迴圈偵測到迴圈
        }
    }
    return 0;  // 沒有偵測到迴圈
}

int main() {
    // 測試範例
    int edges[][2] = {{0, 1}, {1, 2}, {2, 3}, {3, 4}, {4, 0}};
    int numEdges = sizeof(edges) / sizeof(edges[0]);

    int result = hasCycle(edges, numEdges);
    if (result == 1) {
        printf("Have cycle\n");
    } else {
        printf("No cycle\n");
    }

    return 0;
}
