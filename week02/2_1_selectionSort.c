#include<stdio.h>
#define MAX 109
void swap(int i, int j, int arr[])
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void insertionSort(int arr[], int n)
{
    int i, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        swap(i, min, arr);
    }
}

int main()
{
    int n;
    int arr[MAX];
    scanf(" %d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    insertionSort(arr, n);
    for (int i = 0; i < n; i++)
    {
        printf("%d%s", arr[i], (i < n - 1) ? " " : "");
    }
    return 0;
}