#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

typedef struct _Node {
    int val;
    struct _Node* nxt;
} Node;

void reverse(Node** head) {
    Node* now = *head;
    Node* previous = NULL;
    Node* next;

    while (now != NULL)
    {
        next = now->nxt;
        now->nxt = previous;
        previous = now;
        now = next;
    }

    *head = previous;
}

void push_back(Node** head, int n) {
    while (*head)
        head = &(*head)->nxt;

    *head = malloc(sizeof(Node));
    (*head)->val = n;
}

void print(Node* head) {
    while (head) {
        printf("%d ", head->val);
        head = head->nxt;
    }
}

int main(void) {
    int buf;
    Node* head = NULL;
    while (~scanf(" %d", &buf))
        push_back(&head, buf);

    reverse(&head);
    print(head);

    return 0;
}