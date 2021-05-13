#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

int *read(int *len){
	int n = 0;
	FILE *file;
	file = fopen("input.txt", "r");
	assert(file);
	fscanf(file,"%d", &n);
	int **arr = malloc(n * sizeof(int));
	assert(arr);
	int x;
	int i = 0;
	int j = 0;
	for (i = 0; i < n; i++) {
		fscanf(file, "%d", &x);
		arr[i] = malloc(x * sizeof(int));
		assert(arr[i]);
		arr[i][0] = x;
		for (j = 1; j <= x; j++) 
			fscanf(file, "%d", &arr[i][j]);
		fscanf(file, "/n");
	}
	
	fclose(file);

	i = 0;
	do {
		j = 0;
		while(j<=arr[i][0]) {
			printf("%d ",arr[i][j]);
			j++;
		}
		printf("\n");
		i++;
	} while (i < n);
	*len = n;
	return arr;
}



//это обход в ширину

int *bfs(int **arr, int* order, int* marks, int* from, int n) { //breadth-first search
	int start; //rand() % (n - 1);
	printf("Start from: ");
	start = 0;
	scanf("%d", &start);
	order[0] = start;
	from[start] = -1;
	marks[start] = 1;
	int nr = 1; //neighbour
	int v = start; //vertex
	int x = 0;
	int l = 0;
	while (l < n) { //while we haven't gone through all the vertices
		int j = 1;
		for (j = 1; j <= arr[v][0]; j++) { //while vertex's neighbours exist
			x = arr[v][j];
			order[nr++] = x;
			marks[x] = 1;
			if (from[x] == 0)
				from[x] = order[v];
		}
		int pv = v; // previous vertex
		for (j = 1; j <= arr[pv][0]; j++)
			v = arr[pv][j];
		l++;
	}
	return from;
}

int *bfs(int **arr, int n, int start) { //breadth-first search
	int *order = malloc(n * sizeof(int));
	assert(order);
	int *marks = calloc(n, sizeof(int));
	assert(marks);
	int *from = calloc(n, sizeof(int));
	assert(from);
	order[0] = start;
	from[start] = -1;
	marks[start] = 1;
	int nr = 1; //neighbour
	int v = start; //vertex
	int x = 0;
	int l = 0;
	while (l < n) { //while we haven't gone through all the vertices
		int j = 1;
		for (j = 1; j <= arr[v][0]; j++) { //while vertex's neighbours exist
			x = arr[v][j];
			order[nr++] = x;
			marks[x] = 1;
			if (from[x] == 0) 
				from[x] = order[v];
		}
		int pv = v; // previous vertex
		for (j = 1; j <= arr[pv][0]; j++)
			v = arr[pv][j];
		l++;
	}
	return from;
}


int *bfs(int **arr, int* order, int* marks, int* from, int n) { //breadth-first search
	int start; //rand() % (n - 1);
	printf("Start from: ");
	start = 0;
	scanf("%d", &start);
	order[0] = start;
	from[start] = -1;
	marks[start] = 1;
	int nr = 1; //neighbour
	int v = start; //vertex
	int x = 0;
	int l = 0;
	int k = 0;
	while (l < n) { //while we haven't gone through all the vertices
	
		int j = 1;
		for (j = 1; j <= arr[v][0]; j++) { //while vertex's neighbours exist
			x = arr[v][j];
			order[nr++] = x;
			marks[x] = 1;
			if (from[x] == 0)
				from[x] = order[v];
		}
		// previous vertex
		if (k <= arr[v][0]) {
			k++;
			v = arr[v][k];
		}
		l++;
	}
	return from;
}


int srch_entering(int *from, int n, int x, int start) { //array, length, search x from index = start
	int i = start;
	while (from[i] != x && i < n) i++;
	if (from[i] == x) return i;
	return -1;
}

void short_way(int* from, int* way, int n, int a, int b) {
	int k = 0;
	way[k] = a;
	int i = 0;
	int j = a;
	int reserve = 0;
	while (j != b) {
		reserve = j;
		j = srch_entering(from, n, j, i);

		if (j == -1) {
			i++;
			j = srch_entering(from, n, from[reserve], i);
			way[k] = j;
		}
		else {
			k++;
			way[k] = j;
		}
	}
	i = 0;
	printf("Shortest way: ");
	while (way[i] != -1) printf("%d ", way[i]);

}


void main() {
	int n = 0;
	int **arr = read(&n);
	assert(arr != NULL);

	int *from = calloc(n, sizeof(int));
	assert(from);
	int *marks = calloc(n, sizeof(int));
	assert(marks);
	int *order = malloc(n * sizeof(int));
	assert(order);
	from = bfs(arr, order, marks, from, n);

	
	printf("Short way from vertex: ");
	int a = 0;
	scanf("%d", &a);
	printf("To vertex: ");
	int b = 0;
	scanf("%d", &b);
	if (a == b) printf("%d %d", a, b);
	else {
		int *way = calloc(n, sizeof(int));
		assert(way);
		int k = 0;
		while (k < n) way[k++] = -1;
		short_way(from, way, n, a, b);
		free(way);
	}


	
	
	free(arr);
	free(marks);
	free(order);
	free(from);
}
