#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#define unique_ptr __attribute__((cleanup(cleanup_ptr)))

struct node {
    void* addr;
    struct node* nxt;
} *head;

void cleanup_ptr(void* ptr);

void* my_malloc(size_t size) {
    void* addr = malloc(size);
    struct node** node = &head;
    while (*node) {
        node = &(*node)->nxt;
    }
    *node = malloc(sizeof(struct node));
    (*node)->addr = addr;
    (*node)->nxt = NULL;
    return addr;
}

void my_free(void* addr) {
    struct node** node = &head, * target = NULL;
    while (*node && (*node)->addr != addr) {
        node = &(*node)->nxt;
    }
    if (!*node) abort();
    target = *node;
    *node = (*node)->nxt;
    free(target);
    free(addr);
}

/* basic usage */
void case0(void) {
    unique_ptr int* ptr = my_malloc(sizeof(int));
    *ptr = 100;
}

/* different types */
void case1(void) {
    {
        unique_ptr double* ptrd = my_malloc(sizeof(double));
        *ptrd = 3.1415926535;
        unique_ptr float* ptrf = my_malloc(sizeof(float));
        *ptrf = 3.14;
        unique_ptr int* ptri = my_malloc(sizeof(int));
        *ptri = 123456;
    }
    {
        unique_ptr struct foo {
            int a;
            int b;
        }*ptrs = my_malloc(sizeof(struct foo));
        ptrs->a = 123;
        ptrs->b = 456;
        unique_ptr char* ptrc = my_malloc(sizeof(char) * 128);
        *ptrc = 'x';
    }
}

/* large size */
void case2(void) {
    for (int i = 0; i < 100000; i++) {
        unique_ptr char* ptr = my_malloc(sizeof(char) * 100000);
    }
}

void (*test_cases[3])(void) = { &case0, &case1, &case2 };

int main(void) {
    int n;
    scanf("%d", &n);
    test_cases[n]();
    assert(head == NULL);
    puts("finished");
    return 0;
}

void cleanup_ptr(void* ptr) {
    if (NULL != ptr)
    {
        my_free(*(void**)ptr);
    }
}