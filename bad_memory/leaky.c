#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* str;
    for(int i=0;i<3;i++) {
        str = malloc(sizeof(char)*7);
        strcpy(str,"hello!");
        puts(str);
        str = malloc(sizeof(char)*4);
    }
    return 0;
}
