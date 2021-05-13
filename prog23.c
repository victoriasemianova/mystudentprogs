#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>


int* random_sort_arr(int len) {
	int* arr = malloc(len * sizeof(int));
	assert(arr != NULL);
    arr[0] = rand();
	for (int i = 1; i < len; i++)
		arr[i] = arr[i - 1] + (rand()*32768+rand()) % 13 + 2;
	return arr;
}


int simple_search(int*arr, int len, int x) {
	for (int i = 0; i < len; i++)
		if (arr[i] == x) return i;
	return -1;
}


int binary_search_it(int*arr, int l, int r, int x) {
	while (l <= r) {
		int y = arr[(l + r) / 2];
		if (y == x) return (l + r) / 2;
		if (y < x) l = (l + r) / 2 + 1;
		else r = (l + r) / 2 - 1;
	}
	return -1;
}


int binary_search_rec(int *arr, int l, int r, int x) {
	if (l > r) return -1;
	int y = arr[(l + r) / 2]; 
	if (y == x) return (l + r) / 2;
	if (y < x) return binary_search_rec(arr, (l + r) / 2 + 1, r, x);
	else return binary_search_rec(arr, l, (l + r) / 2 - 1, x);
}

void output_failed_test(int *arr, int len, int alg_num, int x) {
	FILE *file;
	file = fopen("output.txt", "w");
	assert(file);
	fprintf(file, "Algoritm number: %d\n", alg_num);
	fprintf(file, "Element: %d\n", x);
	for (int i = 0; i < len; i++)
		fprintf(file, "%d ",arr[i]);
	fclose(file);
}

void main() {
	clock_t start, end;
	printf("			simple		bin_it		bin_rec\n");
	for (int i = 10; i <= 10000000; (i=i*10)) {
		printf("%d		", i);
		int a = 0;
		int b = 0;
		int c = 0;
		for (int j = 1; j <= 10; j++) {
			int len = i;
			int *arr = random_sort_arr(len);
			int k = (rand() * 32768 + rand()) % (i - 1);
			int x0 = arr[k];
			int x = arr[k] + 1;
			int l = 0;
			int r = len - 1;
			int index;

			start = clock();
				index = simple_search(arr, len, x);
			end = clock();
			a += (end - start);
			if (index != k) output_failed_test(arr, len, 1, x); //?

			start = clock();
				index = simple_search(arr, len, x0);
			end = clock();
			a += (end - start);
			if (index != -1) output_failed_test(arr, len, 1, x0);

			start = clock();
				index = binary_search_it(arr, l, r, x);
			end = clock();
			b += (end - start);
			if (index != k) output_failed_test(arr, len, 2, x);

			start = clock();
				index = binary_search_it(arr, l, r, x0);
			end = clock();
			b += (end - start);
			if (index != -1) output_failed_test(arr, len, 2, x0);

			start = clock();
				index = binary_search_rec(arr, l, r, x);
			end = clock();
			c += (end - start);
			if (index != k) output_failed_test(arr, len, 3, x);

			start = clock();
			index = binary_search_rec(arr, l, r, x0);
			end = clock();
			c += (end - start);
			if (index != -1) output_failed_test(arr, len, 3, x0);

			free(arr);
		}
		printf("	%d		%d		%d\n", a/10, b/10, c/10);
	}
	
}