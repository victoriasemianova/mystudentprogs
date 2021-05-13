#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//start of functions from 1 task
int* read(int* lengthp) {
	int x = 0;
	int k = 0;
	int* arr = NULL;
	do {
		scanf("%d", &x);
		if (x != 0) {
			k++;
			arr = realloc(arr, k * sizeof(int));
			if (arr == NULL) {
				printf("Memory wasn't given to you");
				break;
			}
			arr[k - 1] = x;
		}
	} while (x != 0);
	*lengthp = k;
	return arr;
}

void print(int length, int* arr) {
	for (int i = 0; i < length; i++) {
		printf(" %d", arr[i]);
	}
}
//end of functions from 1 task

//start of function from 2 task
int max_arr_ptr(int length, int* arr) {
	int max = arr[0];
	for (int i = 0; i < length; i++)
		if (max < arr[i]) max = arr[i];
	return max;
}
//end of function from 2 task

//start of function from 3 task
int min_inx_arr_ptr(int length, int* arr) {
	int min = arr[0];
	int inx = 0;
	for (int i = 0; i < length; i++)
		if (min > arr[i]) {
			min = arr[i];
			inx = i;
		}
	return inx;
}
//end of function from 3 task

void main() {
	int length = 0;
	int*arr = read(&length);
	if (arr == NULL) printf("Memory wasn't given to you");
	else {
		print(length, arr);
		max_arr_ptr(length, arr);
		min_inx_arr_ptr(length, arr);
		int max = max_arr_ptr(length, arr);
		int inx = min_inx_arr_ptr(length, arr);
		printf("\n max = %d\n min index = %d ", max, inx);
		free(arr);
	}
}

