#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char** argv) {
    char* str;
    str = malloc(sizeof(char)*4);
    strcpy(str,"hello!");
    puts(str);
    return 0;
}
