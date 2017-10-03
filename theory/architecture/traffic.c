/*
 * traffic.c
 *
 *  Created on: Oct 2, 2017
 *      Author: Huseen Sufi
 */
//includes
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//linked list node
typedef struct LinkedRecord {
	char* year;
	int stops;
	struct LinkedRecord * next;
} lr_node;

lr_node* list_find(lr_node* head, char* year) {
	if (head->year == 0) {
		head->year = year;
		head->stops = 0;
		head->next = malloc(sizeof(lr_node));
	}
	if (strcmp(head->year, year) == 0) {
		return head;
	}
	return list_find(head->next, year);
}

char* parse_line(char* line) {
	char* years = malloc(sizeof(char) * 5);
	line = line + 6; //6-10
	strncpy(years,line, 4); //copy dates to years

	//return bogus year if data doesn't convert
	long year;
	char* end;
	year = strtol(years, &end, 4);
	if (year > 0) {
		return years;
	} else {
		return "-1";
	}
}

void print_list(lr_node* head) {
	if (head->year == 0) {
		return;
	}
	printf("%s had %i stops",(head->year,head->stops));
	print_list(head->next);
}

int main(int argc, char** argv) {
	if (argc < 2) {
		printf("Usage: %s <traffic data>\nExiting...\n", argv[0]);
		return -1;
	}

	FILE * f;
	lr_node* out_list = malloc(sizeof(lr_node));
	lr_node* node;
	char* year;
	//below taken from https://stackoverflow.com/questions/3501338/c-read-file-line-by-line
	char* line = 0;
	size_t len = 0;
	ssize_t read;

	f = fopen(argv[1],"r");
	while((read = getline(&line, &len, f)) != -1) {
		year = parse_line(line);
		node = list_find(out_list, year);
		node->stops++;
		printf("node %s, count %d, next: %p\n", node->year, node->stops, node->next);
	}

	fclose(f);
	print_list(out_list);
	if (line) {
		free(line);
	}
	return 0;
}





