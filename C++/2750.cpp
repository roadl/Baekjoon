#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int n, * arr;
	int min, temp;

	scanf("%d", &n);

	arr = (int*)malloc(n * sizeof(int));

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 1; i < n; i++) {
		min = i - 1;

		for (int j = i; j < n; j++) {
			if (arr[min] > arr[j])
				min = j;
		}

		temp = arr[min];
		arr[min] = arr[i - 1];
		arr[i - 1] = temp;
	}

	for (int i = 0; i < n; i++)
		printf("%d\n", arr[i]);

	free(arr);

	return 0;
}