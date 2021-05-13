#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int* read(int* lengthptr) {
	int x = 0;
	int k = 0;
	int* arr = NULL;
	do {
		scanf("%d", &x);
		if (x != 0) {
			k++;
			arr = realloc(arr, k * sizeof(int));
			assert(arr!=NULL);
			arr[k - 1] = x;
		}
	} while (x != 0);
	*lengthptr = k;
	return arr;
}
void split(int *arr, int length, int **arr1, int *length1, int **arr2, int *length2) {
	int k1 = 0;
	int k2 = 0;
	int *arr11 = NULL;
	int *arr22 = NULL;
	for (int i = 0; i < length; i++) {
		if (arr[i] % 2 == 0) {
			k2++;
			arr22 = realloc(arr22, k2 * (sizeof(int)));
			assert((arr22)!=NULL);
			arr22[k2 - 1] = arr[i];
		}
		else {
			k1++;
			arr11 = realloc(arr11, k1 * (sizeof(int)));
			assert((arr11)!=NULL);
			arr11[k1 - 1] = arr[i];
		}
	}
	*length1 = k1;
	*length2 = k2;
	*arr1 = arr11;
	*arr2 = arr22;
}

void print(int length, int* arr) {
	for (int i = 0; i < length; i++) {
		printf(" %d", arr[i]);
	}
}

void main() {
	int length = 0;
	int*arr = read(&length);
	assert(arr != NULL);
	int *arr1 = NULL;
	int length1 = 0;
	int *arr2 = NULL;
	int length2 = 0;
	split(arr, length, &arr1, &length1, &arr2, &length2);
	print(length1, arr1);
	printf("\n");
	print(length2, arr2);
	free(arr);
	free(arr1);
	free(arr2);
}