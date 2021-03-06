#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    size_t T=8;
    int t_hello[T];
    int i=0;
    for(i=0;i<T;i++) {
        t_hello[i]=-1;
   }
   i=0;
    #pragma omp parallel num_threads(8)
    {
	#pragma omp critical
        t_hello[i]=omp_get_thread_num();
        i++;
    }
 
    for(int x = 0;x<T;x++) {
        printf("Hello from %d\n",t_hello[x]);
    }

    return 0;
}

