#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

int** inputMatrix(int* n, int* m) 
{
	int** mat;

	scanf("%d %d", n, m);

	mat = (int**)malloc((*n) * sizeof(int*));

	for (int i = 0; i < (*n); i++)
		mat[i] = (int*)malloc((*m) * sizeof(int));

	for (int i = 0; i < (*n); i++)
		for (int j = 0; j < (*m); j++)
			scanf("%d", &mat[i][j]);

	return mat;
}

int main()
{
	int n1, m1, n2, m2, ** mat1, ** mat2;

	mat1 = inputMatrix(&n1, &m1);
	mat2 = inputMatrix(&n2, &m2);

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m2; j++) {
			int n = 0;

			for (int k = 0; k < m1; k++) {
				n += mat1[i][k] * mat2[k][j];
			}

			printf("%d ", n);
		}

		printf("\n");
	}

	for (int i = 0; i < n1; i++)
		free(mat1[i]);
	for (int i = 0; i < n2; i++)
		free(mat2[i]);

	free(mat1);
	free(mat2);

	return 0;
}