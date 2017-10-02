/**
 * This program highlights the significance of being consistent in lock and unlock order.
 *
 * Each of the functions appears reasonable on its own and releases the held locks as
 * early as possible. If you would like to try fixing this program, you'll need to use
 * nested locks rather than the normal locks since task_a and bar both need the same lock 
 * (which is ok since execution is in the same thread and therefore the same as serial).
 */ 
#include <omp.h>
#include <stdio.h>
#include <stdlib.h>

omp_lock_t lockA;
omp_lock_t lockB;
omp_lock_t lockC;

void task_a();
void task_b();
void foo();
void bar();

int main(int argc, char** argv) {
    int i;
    omp_init_lock(&lockA);
    omp_init_lock(&lockB);

    #pragma omp parallel for
    for(i=0;i<1000;i++) {
        if(i%2==0) {
            task_a();
        } else {
            task_b();
        }
    }
    return 0;
}

void task_a() {
    omp_set_lock(&lockA);
    omp_set_lock(&lockB);
    foo();
    omp_unset_lock(&lockA);
    bar();
    omp_unset_lock(&lockB);
}

void task_b() {
    omp_set_lock(&lockA);
    omp_set_lock(&lockB);
    printf("b"); fflush(stdout);
    omp_unset_lock(&lockB);
    omp_unset_lock(&lockA);
}

void foo() {
    printf("f"); fflush(stdout);
}

void bar() {
    omp_set_lock(&lockA);
    printf("b"); fflush(stdout);
    omp_unset_lock(&lockA);
}