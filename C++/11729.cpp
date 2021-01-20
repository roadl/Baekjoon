#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <math.h>

void hanoi(int start, int dest, int other, int n) 
{
	if (n == 1)
		printf("%d %d\n", start, dest);
	else {
		hanoi(start, other, dest, n - 1);
		printf("%d %d\n", start, dest);
		hanoi(other, dest, start, n - 1);
	}
}

int main()
{
	int n;

	scanf("%d", &n);
	printf("%.0f\n", pow(2, n) - 1);
	hanoi(1, 3, 2, n);

	return 0;
}