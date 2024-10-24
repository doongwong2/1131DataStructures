#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#define MAX 108

int arr[MAX] = { 0 };

int binarySearch(int target, int left, int right)
{
		int middle = left + (right - left) / 2;
		if (target == arr[middle]) return middle;
		else if (target < arr[middle]) return binarySearch(target,left, middle - 1);
		else return binarySearch(target, middle + 1, right);
}

int main()
{
	int target, n;
	scanf(" %d %d", &target, &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	printf("%d", binarySearch(target, 0, n - 1));
	return 0;
}