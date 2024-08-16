#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    start = clock();
    long long a = 0;
    long long b = 1;
    printf("%lld %lld ", a, b);
    long long c;
    for (int i = 2; i < 50; i++) {
        c = a + b; //fibonacci number caculation
        a = b;
        b = c;
        printf("%lld ", c);
    }
    end = clock();
    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("\nProgram 1 (baseline) execution time: %f seconds\n", cpu_time_used);
    free(c);
    return 0;
}