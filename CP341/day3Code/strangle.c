/**
 * This program demonstrates strangled scaling.
 * The intent of the program is to print hello world on one line using two print 
 * statements. There is no need for the sleep to be within the critical region, since
 * there is no harm in sleeping in parallel.
 */ 
#include <stdio.h>
#include <unistd.h>
#include <omp.h>

int main(int argc, char** argv) {
   int i;
   omp_lock_t lock;
   omp_init_lock(&lock);
   #pragma omp parallel num_threads(16)
   #pragma omp for
   for(i=0;i<16;i++) {
      omp_set_lock(&lock);
      sleep(1);
      printf("Hello ");
      printf("world %d\n",i);
      omp_unset_lock(&lock);
   }
   return 0;
}
