#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 1000

char input[MAX];
char find[30];
char replace[30];
char result[MAX];

void findAndReplace() {
    int i = 0, j = 0;

    find[strcspn(find, "\n")] = 0;
    replace[strcspn(replace, "\n")] = 0;
    
    int fLen = strlen(find);
    int rLen = strlen(replace);
    
    while (input[i] != '\0') {

        if (strncmp(&input[i], find, fLen) == 0) {

            strcpy(&result[j], replace);
            j += rLen;
            i += fLen;
        }
        else {
            result[j++] = input[i++];
        }
    }
    result[j] = '\0';

    printf("%s", result);
}

int main() {
    
    fgets(input, MAX - 1, stdin);
    fgets(find, sizeof(find), stdin);
    fgets(replace, sizeof(replace), stdin);

    findAndReplace();

    return 0;
}
