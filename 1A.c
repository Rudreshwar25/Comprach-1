#include <stdio.h>
#include <stdlib.h>
#include <time.h>
long long f(int n, long long *a) {
    if (n <= 1) { //base case
        return n;
    }
    return a[n] = f(n - 1, a) + f(n - 2, a);// stroed in this to write the output
}

int main() {
    clock_t start, end;
    start = clock();
    long long *c = (long long *)calloc(51, sizeof(long long));
    c[0] = 0; //fibnacci(0) is 0
    c[1] = 1; //fibnacci(1) is 1
    f(50, c);
    for (int i = 0; i < 50; i++) {
        printf("%lld ", c[i]);
    }
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nProgram 1 (baseline) execution time: %f seconds\n", cpu_time_used);
    free(c);

    return 0;
}