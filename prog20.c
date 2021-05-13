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


int* bisorting(int *arr1, int *arr2, int maxlength, int minlength) {
	int *arr = malloc((maxlength + minlength) * sizeof(int));
	assert(arr!=NULL);
	int k = 0;
	int i = 0;
	int j = 0;
	while ((i != maxlength) && (j != minlength)) {
		if (arr1[i] < arr2[j]) {
			arr[k] = arr1[i];
			k++;
			i++;
		}
		else {
			if (arr1[i] == arr2[j]) {
				arr[k] = arr2[j];
				arr[k + 1] = arr2[j];
				k = k + 2;
				j++;
				i++;
			}
			else {
				arr[k] = arr2[j];
				k++;
				j++;
			}
		}
	}

	if (j == minlength)
		for (int l = i; l < maxlength; l++) {
			arr[k] = arr1[l];
			k++;
		}
	else
		for (int l = j; l < minlength; l++) {
			arr[k] = arr2[l];
			k++;
		}
	return arr;
}


void print(int length, int* arr) {
	for (int i = 0; i < length; i++) {
		printf(" %d", arr[i]);
	}
}


void main() {
	int length1 = 0;
	int length2 = 0;
	int *arr1 = read(&length1);
	int *arr2 = read(&length2);
	assert(arr1!=NULL);
	assert(arr2!=NULL);
	if (length1 >= length2) bisorting(arr1, arr2, length1, length2);
	else bisorting(arr2, arr1, length2, length1);
	int *arr3 = bisorting(arr2, arr1, length2, length1);
	print(length1 + length2, arr3);
	free(arr1);
	free(arr2);
	free(arr3); 
}