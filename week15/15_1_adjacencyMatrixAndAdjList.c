#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX(a, b) (((a) > (b)) ? (a) : (b))
#define SIZE 100

typedef struct {
    int size;
    int reserve_size;
    int* arr;
} vector;

void push_back(vector* v, int x) {
    if (v->size >= v->reserve_size) {
        v->reserve_size *= 2; // Double the reserve size
        int* new_arr = realloc(v->arr, v->reserve_size * sizeof(int)); // Allocate enough space
        if (new_arr == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE); // Exit if memory allocation fails
        }
        v->arr = new_arr; // Update the pointer to the new memory
    }
    v->arr[v->size++] = x; // Add the new element
}

int main() {
    int a, b, n = -1;
    vector node[1000];
    int arr[SIZE][SIZE];
    memset(arr, 0, sizeof(arr));

    for (int i = 0; i < 1000; i++) {
        node[i].size = 0;
        node[i].reserve_size = 1;
        node[i].arr = malloc(sizeof(int)); // Initial allocation for the array
        if (node[i].arr == NULL) {
            perror("Failed to allocate memory");
            exit(EXIT_FAILURE); // Exit if memory allocation fails
        }
    }

    while (scanf("%d %d", &a, &b) != EOF) {
        arr[a][b] = 1;
        arr[b][a] = 1;
        push_back(&node[a], b);
        push_back(&node[b], a);
        n = MAX(n, a);
        n = MAX(n, b);
    }
    n++;

    printf("Adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d", arr[i][j]);
            if (j != n - 1) printf(" ");
        }
        printf("\n");
    }

    printf("\n");

    printf("Adjacency list:\n");
    for (int i = 0; i < n; i++) {
        printf("%d:", i);
        for (int j = 0; j < node[i].size; j++) {
            printf(" %d ->", node[i].arr[j]);
        }
        printf(" end\n");
    }

    // Free allocated memory
    for (int i = 0; i < 1000; i++) {
        free(node[i].arr);
    }

    return 0;
}
