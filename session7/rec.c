#include <stdio.h>
#include <stdlib.h>

long long fib(int n);
long long fac(int n);
int sum_digits(int n);
long long naive_pow(int x, int n);
long long log_pow(int x, int n);
long long better_log_pow(int x, int n);
int str_len(char *str);

/* pre-condition: n is a non negative number*/
int main(int argc, char **argv) {

    if (argc != 2) {
        fprintf(stderr, "Usage: %s <int>\n", *argv);
        return 1;
    }
    int n = abs(atoi(argv[1]));

    // Fibonacci
    printf("Fib(%d) = %lld.\n", n, fib(n));

    // Factorial
    printf("Fac(%d) = %lld.\n", n, fac(n));
    
    // Sum digits 
    printf("Sum_digits(%d) = %d.\n", n, sum_digits(n));

    // Pow
    printf("Naive_pow(%d, %d) = %lld.\n", n, n, naive_pow(n, n));
    printf("Log_pow(%d, %d) = %lld.\n", n, n, log_pow(n, n));
    printf("Better_log_pow(%d, %d) = %lld.\n", n, n, better_log_pow(n, n));

    // String len
    char str[] = "This is a cool string";
    printf("len(%s) = %d.\n", str, str_len(str));

    return 0;
}

long long fib(int n) {

    if (n <= 1) {
        return 1;
    }

    return fib(n - 1) + fib(n - 2);
}

long long fac(int n) {

    if (n <= 1) {
        return 1;
    }

    return n * fac(n - 1);
}

int sum_digits(int n) {

  if (n < 10) {
    return n;
  }

  return (n % 10) + sum_digits((int) n / 10);
}

// Compute x^n
long long naive_pow(int x, int n) {

    if (n <= 1) {
        return x;
    }

    return x * naive_pow(x, n - 1);
}

long long log_pow(int x, int n) {

    if (n <= 1) {
        return x;
    }

    if (n % 2 == 0) {
        return log_pow(x, (int) n/2) * log_pow(x, (int) n/2);
    }
    else {
        return x * log_pow(x, (int) (n - 1)/2) * log_pow(x, (int) (n - 1)/2);
    }
}

long long better_log_pow(int x, int n) {

    if (n <= 1) {
        return x;
    }

    if (n % 2 == 0) {
        long long y = log_pow(x, (int) n/2);
        return y * y;
    }
    else {
        long long y = log_pow(x, (int) (n - 1)/2);
        return x * y * y;
    }
}

int str_len(char *str) {

  if (*str == '\0') {
    return 0;
  }

  return 1 + str_len(++str);
}
