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
			assert(arr != NULL);
			arr[k - 1] = x;
		}
	} while (x != 0);
	*lengthptr = k;
	return arr;
}

int find(int *arr1, int *arr2, int length1, int length2) {
	int index = -1;
	for (int i = 0; i < length1; i++) {
		if ((arr1[i] == arr2[0]) && (length1 - i >= length2)) {
			int k = ++i;
			int j = 1;
			while (j < length2)
				if (arr1[k] == arr2[j]) {
					k++;
					j++;
				}
			if (j == length2) return i - 1;
		}

	}
	return -1;
}


void main() {
	int length1 = 0;
	int length2 = 0;
	int*arr1 = read(&length1);
	int*arr2 = read(&length2);
	assert(arr1 != NULL);
	assert(arr2 != NULL);
	int i = find(arr1, arr2, length1, length2);
	printf(" %d ", i);
	free(arr1);
	free(arr2);
}