/**
 * This program highlights spacial data locality.
 * The program works only with the x component of the points being processed. Representing
 * the data as a struct of arrays allows for better cache utilization since the y and z
 * data will not take up cache.
 */ 
#include <stdio.h>
#include <stdlib.h>

size_t MAX_IDX=1000000000;

struct _point {
    float x;
    float y;
    float z;
};

struct _points {
    float* x;
    float* y;
    float* z;
};

void struct_of_array() {
    struct _points out;
    out.x = calloc(MAX_IDX,sizeof(float));
    out.y = calloc(MAX_IDX,sizeof(float));
    out.z = calloc(MAX_IDX,sizeof(float));

    for(size_t i=0; i<MAX_IDX; i++) {
       out.x[i]=i;
    }
}

void array_of_struct() {
    struct _point* out;
    out = calloc(MAX_IDX,sizeof(struct _point));
    
    for(size_t i=0; i<MAX_IDX; i++) {
        out[i].x=i;
    }
}

int main(int argc, char** argv) {
    //struct_of_array();
    array_of_struct();
    return 0;
}

