/*
 * fib.c
 *
 *  Created on: Sep 25, 2017
 *      Author: Huseen Sufi
 */


#include <stdio.h>
#include <stdlib.h>
void runFib(int);

void runFib(int n) {
	int i = 0;

	for (int x = 0; x < n; ++x) {
		printf("%i", fib(i));
		++i;
	}
}

int fib(int n) {

	if (n == 0 ) {
		return 0;
	} else if (n == 1){
		return 1;
	} else {
		return (fib(n-1) + fib(n-2));
	}
}
