//this is still in work.
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

typedef struct listNode* listPointer;
struct listNode {
    char data[4];
    listPointer link;
};

void insert(listPointer* first, listPointer x)
{
    /* insert a new node with data = 50 into the chain first after node x */
    listPointer temp;
    temp = (listPointer)malloc(sizeof(*temp));
    if (IS_FULL(temp)) {
        printf("The memory is full\n");
        exit(1);
    }
    temp->data = 50;
    if (*first) {             //Case 1
        temp��link = x��link;
        x��link = temp;
    }
    else {                    //Case 2
        temp��link = NULL;
        *first = temp;
    }
}

void delete(listPointer* first, listPointer trail, listPointer x)
{
    /* delete x from the list, trail is the preceding node and *first is the front of the list */
    if (trail)         // Case 1
        trail��link = x��link;
    else              // Case 2
        *first = (*first)��link;
    free(x);
}

void printList(listPointer first)
{
    printf(��The list contains : ��);
    for (; first; first = first��link)
        printf(�� % 4d��, first��data);
    printf(��\n��);
}
