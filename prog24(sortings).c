#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>

int* random_arr(int length) {
	int* arr = malloc(length * sizeof(int));
	assert(arr != NULL);
	for (int i = 0; i < length; i++)
		arr[i] = rand() % 10;
	return arr;
}


//вспомогательные функции
void swap(int *a, int *b) {
	int c = *a;
	*a = *b;
	*b = c;
}


void output_failed_test(int *arr, int len, int alg_num) {
	FILE *file;
	file = fopen("output1.txt", "w");
	assert(file);
	fprintf(file, "Algoritm number: %d\n", alg_num);
	for (int i = 0; i < len; i++)
		fprintf(file,"%d  ", arr[i]);
	fclose(file);
}


int simple_search(int* arr, int* x, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] != x) return -1;
	}
}

int proverka(int *arr, int len, int* res_arr, int alg_num) {
	for (int l = 0; l < len; l++) {
		if ((simple_search(arr, &res_arr[l], len)) == -1)
			output_failed_test(arr, len, alg_num);
	}
}


void check_sort(int *arr, int len, int alg_num) {
	for (int i = 0; i < len-1; i++)
	if (arr[i + 1] < arr[i]) output_failed_test(arr, len, alg_num);
}


int promezh_check_sort(int *arr, int len) {
	for (int i = 0; i < len-1; i++)
	if (arr[i + 1] < arr[i]) return -1;
}


int choice_basic2(int *arr, int l, int r) {
	int mid = (l + r) / 2;
	int s = arr[l] + arr[mid] + arr[r];
    return s / 3;
}

int choice_basic3(int *arr, int l, int r) {
	int len = r - l + 1;
	int k = len - 1;
	int a = arr[l];
	int b = arr[l + k / 2];
	int c = arr[l + k];
	if ((a > b && a < c) ||
		(a < b && a > c))
		return l;
	if ((b > a && b < c) ||
		(a > b && c > b))
		return l + k / 2;
	else return l + k;
}

void bisorting(int *arr1, int *arr2, int *arr, int n) {
	int i = 0;
	int j = 0;
	int k;
	int l = n / 2;
	int r = n - l;
	for (k = 0; k < n && i < l && j < r; k++) {
		if (arr1[i] < arr2[j]) {
			arr[k] = arr1[i++];
		}
		else {
			arr[k] = arr2[j++];
		}
	}
	while (i < l) {
		arr[k++] = arr1[i];
		i++;
	}
	while (j < r) {
		arr[k++] = arr2[j];
		j++;
	}
}

int build_btree(int *arr, int l, int r) {
	int max = l;
	int t;
	do {
		t = max;
		int lt = 2 * t + 1;
		int rt = 2 * (t + 1);
		if (lt <= r)
			if (arr[lt] > arr[t]) max = lt;
		if (rt <= r)
			if (arr[rt] > arr[max]) max = rt;
		swap(&arr[t], &arr[max]);
	} while (t != max);
	return 0;
}

//сортировка 1
int *bubble_sort(int *arr, int len) {
	for (int j = 1; j < len; j++) {
		for (int i = 0; i < len - j; i++) {
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
		}
		if (promezh_check_sort(arr, len) != -1) return arr;
	}
	return arr;
}


//сортировка 2
int *sick_bubble_sort(int *arr, int len) {
	for (int k = 1; k <= (len - 1) / 2; k++) {
		for (int i = k - 1; i < len - k; i++) {
			if (arr[i] > arr[i + 1])
				swap(&arr[i], &arr[i + 1]);
		}
		if (promezh_check_sort(arr, len) != -1) return arr;

		for (int j = len - k - 1; j >= k; j--) {
			if (arr[j] < arr[j - 1])
				swap(&arr[j], &arr[j - 1]);
		}
		if (promezh_check_sort(arr, len) != -1) return arr;
	}
	return arr;
}

//сортировка 3
void gnom_sort(int *arr, int len) {
	int i = 1;
	while (i < len) {
		if (arr[i] < arr[i - 1]) {
			swap(&arr[i], &arr[i - 1]);
			if (i > 1) i--;
		}
		else i++;
	}
}

//сортировка 4,5,6
void quick_sort( int *arr, int left, int right, int k){
	if (left < right && right - left + 1 > 1) {
		int len = right - left + 1;
		int basic;
		if (k == 1) basic = arr[rand() % (right - left + 1) + left];
		if (k == 2) basic = choice_basic2(arr, left, right);
		if (k == 3) basic = arr[choice_basic3(arr, left, right)];
		int l = left;
		int r = right;
		do {
			while (arr[l] < basic)l++;
			while (arr[r] > basic)r--;
			if (l <= r) {
				if (l < r) {
					swap(&arr[l], &arr[r]);
				}
				l++;
				r--;
			}
		} while (l <= r);
		if (r >= left)
		quick_sort(arr, left, r, k);
		quick_sort(arr, l, right, k);
	}
}

//сортировка 7
void merge_sort(int *arr, int len) {
	if (len == 1) {
		return;
	}
	if (len == 2) {
		if (arr[0] > arr[1]) {
			swap(&arr[0], &arr[1]);
		}
		return;
	}
	int half = len / 2;
	merge_sort(arr, half);
	merge_sort(arr + half, len - half);
	int* another_arr = malloc(len * sizeof(int));
	bisorting(arr, arr + half, another_arr, len);
	for (int i = 0; i < len; i++) {
		arr[i] = another_arr[i];
	}
}

//сортировка 8
void piramid_sort(int *arr, int len) {
	int i;
	for (i = (len - 1) / 2; i >= 0; i--)
		build_btree(arr, i, len - 1);
	for (i = len - 1; i >= 0; i--) {
		swap(&arr[0], &arr[i]);
		build_btree(arr, 0, i - 1);
	}
}






void main() {
	clock_t start, end;
	int *arr;
	printf("                   1    2    3    4    5    6    7    8\n");
	for (int len = 10; len <= 1000; (len = len * 10)) { //до 1000, потому что иначе stack overflow
		printf("%d		", len);
		int a = 0;
		int b = 0;
		int c = 0;
		int d = 0;
		int e = 0;
		int f = 0;
		int g = 0;
		int h = 0;
		for (int j = 1; j <= 10; j++) {

			//пузырек
			arr = random_arr(len);
			int* res_arr1 = malloc(len * sizeof(int));
			for (int k = 0; k < len; k++)
				res_arr1[k] = arr[k];
			start = clock();
			arr = bubble_sort(arr, len);
			end = clock();
			a += (end - start);
			check_sort(arr, len, 1);
			proverka(arr, len, res_arr1, 1);//элементы совпадают?
			free(res_arr1);




			//хороший пузырек
			arr = random_arr(len);
			int *res_arr2 = malloc(len* sizeof(int));
			for (int k = 0; k < len; k++)
				res_arr2[k] = arr[k];
			start = clock();
			arr = sick_bubble_sort(arr, len);
			end = clock();
			b += (end - start);
			check_sort(arr, len, 2);
			proverka(arr, len, res_arr2, 2);
			free(res_arr2);

			
			
			//гномья
			arr = random_arr(len);
			int *res_arr3 = malloc(len * sizeof(int));
			for (int k = 0; k < len; k++)
				res_arr3[k] = arr[k];
			start = clock();
			gnom_sort(arr, len);
			end = clock();
			c += (end - start);
			check_sort(arr, len, 3);
			proverka(arr, len, res_arr3, 3);
			free(res_arr3);

			//быстрая
			int k = 1;
			while (k <= 3) {
				arr = random_arr(len);
				arr = random_arr(len);
				int *res_arr4 = malloc(len * sizeof(int));
				for (int k = 0; k < len; k++)
					res_arr4[k] = arr[k];
				start = clock();
				quick_sort(arr, 0, len-1, k);
				end = clock();
				if (k == 1) d += (end - start);
				if (k == 2) e += (end - start);
				if (k == 3) f += (end - start);
				check_sort(arr, len, k + 3);
				proverka(arr, len, res_arr4, k + 3);
				free(res_arr4);
				k++;
			}

			//слиянием
			arr = random_arr(len);
			int *res_arr7= malloc(len * sizeof(int));
			for (int k = 0; k < len; k++)
				res_arr7[k] = arr[k];
			start = clock();
			merge_sort(arr, len);
			end = clock();
			g += (end - start);
			check_sort(arr, len, 7);
			proverka(arr, len, res_arr7, 7);
			free(res_arr7);
			

		
			//пирамидальная
			arr = random_arr(len);
			int *res_arr8 = malloc(len * sizeof(int));
			for (int k = 0; k < len; k++)
				res_arr8[k] = arr[k];
			start = clock();
			piramid_sort(arr, len);
			end = clock();
			h += (end - start);
			check_sort(arr, len, 8);
			proverka(arr, len, res_arr8, 8);
			free(res_arr8);
			
			free(arr);

		}
		printf("   %d    %d    %d    %d    %d    %d    %d    %d\n", a / 10, b / 10, c / 10, d / 10, e / 10, f / 10, g / 10, h / 10);
	}
}