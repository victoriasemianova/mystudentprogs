#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef struct {
	int size;
	int cap;
	int *array;
} str;



void init_str(str*arr) {
	arr->size = 0;
	arr->cap = 4;
	arr->array = malloc(arr->cap * sizeof(int));
	assert(arr->array != NULL);
}

void free_str(str*arr) {
	free(arr->array);
}

int get(str*arr, int index) {
	return arr->array[index];
}

void set(str*arr, int index, int value) {
	arr->array[index] = value;
}


void add_tail(str *arr, int x) {
	if (arr->size == arr->cap) {
		arr->array = realloc(arr->array, arr->cap * 2 * sizeof(int));
		assert(arr->array != NULL);
		arr->cap *= 2;
	}
	set(arr, arr->size++, x);
}

void add_head(str *arr, int x) {
	if (arr->size == arr->cap) {
		arr->array = realloc((arr->array), (arr->cap * 2) * sizeof(int));
		assert(arr->array != NULL);
		arr->cap *= 2;
	}
	for (int j = arr->size; j > 0; j--) {
		set(arr, j, get(arr, j - 1));
	}
	set(arr, 0, x);
	arr->size++;
}

void remove_tail(str*arr) {
	arr->size--;
}

void remove_head(str*arr) {
	if (arr->size != 0) {
		arr->size--;
		for (int j = 1; j <= arr->size; j++)
			set(arr, j - 1, get(arr, j));
	}
}


void test_add_tail() {
	str x;
	int k;
	init_str(&x);
	for (int i = 87; i < 100; i++) {
		add_tail(&x, i);
		k = i;
	}
	assert(get(&x, 0) == k);
	free_str(&x);
}

void test_add_head() {
	str x;
	init_str(&x);
	int k;
	for (int i = 87; i < 1000; i++) {
		add_tail(&x, i);
		add_head(&x, i * 17);
		k = i * 17;
	}
	assert(get(&x, 0) == k);
	free_str(&x);
}

void test_remove_tail() {
	str x;
	init_str(&x);
	add_tail(&x, 42);
	remove_tail(&x);
	assert(x.size == 0);
	free_str(&x);
}

void test_remove_head() {
	str x;
	init_str(&x);
	add_head(&x, 42);
	add_head(&x, 41);
	remove_head(&x);
	assert(x.size == 1);
	assert(get(&x, 0) == 42);
	free_str(&x);
}


void main() {
	test_add_tail();
	test_add_head();
	test_remove_tail();
	test_remove_head();
}