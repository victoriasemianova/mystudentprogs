#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>



int strlen(const char *str) {
	int i = 0;
	while (str[i++]);
	return i-1;
}

char *strcpy(char *dst, const char *src) {
	int len = strlen(src);
	int i;
	for (i = 0; i < len; i++)
		dst[i] = src[i];
	dst[i] = '\0';
	return dst;
}


int strcmp(const char *s1, const char *s2) {
	int i = 0;
	while (s1[i] && s2[i]) {
		if (s1[i] < s2[i]) return -1;
		if (s1[i] > s2[i]) return 1;
		else i++;
	}
	if (s1[i] != 0) return -1;
	if (s2[i] != 0) return 1;
	else return 0;
}


char *strcat(char *dst, const char *src) {
	
	int len1 = strlen(dst);
	int len = len1 + strlen(src);
	int i = 0;
	while (i < (len-len1)) {
		dst[i + len1] = src[i];
		i++;
	}
	dst[i] = '\0';
	return dst;
}

int str_search_f(const char *str,const char c) {
	int i = 0;
	while (str[i] != c&& str[i] != 0) i++;
	if (str[i] == c) return &str[i];
	return NULL;
}

int str_search_l(const char *str,const char c) {
	int i = strlen(str) - 1;
	while ((str[i] != c) && (i != 0)) i--;
	if (str[i] == c) return &str[i];
	return NULL;
}

int str_search_entering(const char* str, const char c, int start) {
	int len = strlen(str);
	for (int i = start; i < len; i++) {
		if (str[i] == c) return i;
	}
	return -1;
}

int str_search_str(const char *needle, const char *haystack, int start) {
	int index = str_search_entering(haystack, needle[0], start);
	if (index != -1) {
		int j = 1;
		int len_hst = strlen(haystack);
		int len_ndl = strlen(needle);
		while (haystack[index + j] == needle[j] && haystack[index + j] && needle[j]) j++;
		if (haystack[index + j] != needle[j] && len_hst - index >= len_ndl && needle[j] != '\0') {
			index = str_search_str(needle, haystack, index + j);
			return index;
		}
		if (needle[j] == '\0') return index;

	}
	else return -1;
}



void main() {
	/*
	char str1[100] = { 0 };
	char str2[100] = { 0 };
	printf("Please, write string 1\n");
	scanf("%s", &str1);
	printf("\nYou are so kind!\nThat's your length: %d\n", strlen(&str1));
	char str11[100] = { 0 };
	printf("\nMay I copy what you've said?!\nHope you don't mind: %s\n", strcpy(&str11, &str1));

	printf("\nI didn't want to ask you..\nBut please, write string 2\n");
	scanf("%s", &str2);
	printf("\nI've compared and here is a result: %d\n", strcmp(&str1, &str2));
	printf("\nI've concatenated and here is a result: %s\n", strcat(&str1, &str2));
	
	printf("\nI wanna find somthing in your string, write a letter\n");
	char c;
	scanf("\n%c", &c);
	printf("First entering adress: %d\n", str_search_f(&str1, c));
	printf("Last entering adress: %d\n", str_search_l(&str1, c));
	
	char str3[100] = { 0 };
	printf("\nPlease, write string 3\n");
	scanf("%s", &str3);
	printf("\nFirst entering adress of third string in first: %d\n", str_search_str(&str3, &str1, 0));
	*/

	char s1[20];
	char s2[20] = "Hello";
	printf("%s\n", s2);
	strcpy(s1, s2);
	printf("%s\n", s1);
}