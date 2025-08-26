#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <limits.h>

#define MAX 100010

int arr[MAX] = { 0 };

long long largestNonAdjacentSum(int n);
long long myMax(int a, int b);

int main() {
    int n;
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("%lld\n", largestNonAdjacentSum(n));

    return 0;
}

long long largestNonAdjacentSum(int n) {
    if (n == 0) return 0;
    if (n == 1) return arr[0];
    if (n == 2) return (arr[0] > arr[1]) ? arr[0] : arr[1];

    int ans = INT_MIN,max = arr[0];
    for (int i = 2; i < n; i++)
    {
        ans = myMax(ans, max + arr[i]);
        max = myMax(max,arr[i - 1]);
    }

    return (long long)ans;
}

long long myMax(int a, int b)
{
    if (b > a) return b;
    return a;
}
