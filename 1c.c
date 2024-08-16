#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to compute Fibonacci number with memoization
long long f(int n, long long *a) {
    // Base cases: fib(0) = 0, fib(1) = 1
    if (n <= 1) {
        return n;
    }
    if (a[n] != -1) {
        return a[n];
    }
    a[n] = f(n - 1, a) + f(n - 2, a);
    return a[n];
}

int main() {
    clock_t start, end;
    int size = 50;
    long long *a = (long long *)calloc(size, sizeof(long long));

    if (a == NULL) {
        printf("Memory allocation failed\n");
        return 1;
    }

    for (int i = 0; i < size; i++) {
        a[i] = -1;
    }

    // Base cases
    a[0] = 0;
    a[1] = 1;

    start = clock();
    f(size - 1, a); // Compute Fibonacci numbers up to index size-1
    end = clock();

    // Print the Fibonacci sequence
    for (int i = 0; i < size; i++) {
        printf("%lld ", a[i]);
    }
    printf("\n");

    double cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Program execution time: %f seconds\n", cpu_time_used);

    free(a);
    return 0;
}