/*
 * read_reverse_write.c
 *
 *  Created on: Sep 29, 2017
 *      Author: Huseen Sufi
 */


#include <stdio.h>
#include <stdlib.h>

int main(int argc, char**argv) {
	FILE* f;
	int e; //error code returned
	int b; //bytes actually read--in this case chars are one byte big
	char* in_buf = malloc(sizeof(char)*100); //breaks on big files
	char* out_buf = malloc(sizeof(char)*100);

	//read
	f = fopen(argv[1],"r");
	b = fread(in_buf, sizeof(char), 100, f);
	//check value of b here
	e = fclose(f);
	//check f close

	//reverse
    for(int i=b-1; i>-1; i--) {
    	out_buf[b-1-i] = in_buf[i];
    }

    //write
    printf("writing:\n%s\n",out_buf);
    f = fopen(argv[2],"w");
    b = fwrite(out_buf, sizeof(char), b, f);
    //check b again
    fclose(f);

    return 0;
}
