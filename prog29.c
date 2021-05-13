#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <malloc.h>
#include <assert.h>
#include <conio.h>

typedef struct elem {
	int info;
	struct elem* next;
}elem;

typedef struct list {
	elem* head;
}list;

void init_list(list* obj){
	obj->head = NULL;
}

void list_add_head(list* obj, int x) {
	elem* e = malloc(sizeof(elem));
	e->info = x;
	e->next = obj->head;
	obj->head = e;
}

int list_size(list* obj) {
	int n = 0;
	elem* tmp;
	tmp = obj->head;
	while (tmp) 
		tmp = tmp->next;
	return n;
}

int sortlist_add(list* obj, int x) {
	elem* tmp;
	tmp = obj->head;
	while (tmp->info < x) tmp = tmp->next;
	elem* e = malloc(sizeof(elem));
	e->info = x;
	e->next = tmp;
	tmp = e;
}

void list_del(list* obj, int n) {
	elem* tmp = obj->head;
}

main(){

	//notint* head = NULL;
	//elem* head = malloc(sizeof(elem));
	//assert(head);
	//head = create_list(head);
	//getchar();
}




/*
notint* create_list(notint* head) {

	notint* p = head;
	for (int i = 1; i < 5; i++) {
		if (i != 1) {
			p = malloc(sizeof(notint));
			assert(head);
		}
		p->info = i;
		if (i != 4) {
			p->next = malloc(sizeof(notint));
			assert(head);
			p = p->next;
		}
		else p->next = NULL;
	}
	return head;
}
*/










