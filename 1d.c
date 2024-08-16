#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
clock_t start, end;
start = clock();
    long long *a = (long long *)calloc(50, sizeof(long long));

    // fib(0)=0 fib[1]=1;
    
    a[1] = 1;
    a[0]=0;
    
    printf("%lld %lld ", a[0], a[1]);
    for (int i = 2; i <= 50; i++) {
        a[i] = a[i - 1] + a[i - 2];
        printf("%lld ", a[i]);
    }
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nProgram 1 (baseline) execution time: %f seconds\n", cpu_time_used);

    free(a);

    return 0;
}