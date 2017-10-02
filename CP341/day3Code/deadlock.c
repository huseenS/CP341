/** 
 * This program demonstrates a simple deadlock involving lock acquisition order.
 * Locks should always be acquired and released in the same order. The lock_order.c
 * file contains an example demonstrating that the order in which locks are released
 * is significant.
 */
 
#include <omp.h>
#include <stdio.h>

int main(int argc, char** argv) {
    omp_lock_t lockA;
    omp_lock_t lockB;

    omp_init_lock(&lockA);
    omp_init_lock(&lockB);

    int a=0;
    #pragma omp parallel for
    for(int i=0; i<1000; i++) {
        if(i%2==0) {
            printf("+"); fflush(stdout);
            omp_set_lock(&lockA);
            omp_set_lock(&lockB);
            a+=1;
            printf("."); fflush(stdout);
            omp_unset_lock(&lockB);
            omp_unset_lock(&lockA);
        } else {
            printf("-"); fflush(stdout);
            omp_set_lock(&lockB);
            omp_set_lock(&lockA);
            a-=1;
            printf("."); fflush(stdout);
            omp_unset_lock(&lockA);
            omp_unset_lock(&lockB);
        }
    }
    printf("\n%d\n",a);
    return 0;
}
