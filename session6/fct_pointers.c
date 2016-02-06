#include <stdio.h>
#include <stdlib.h>

int add(int a, int b);
int mul(int a, int b);
int divi(int a, int b);
int sub(int a, int b);

void perform_operation(int (*f)(int, int), 
    const int* a, const int* b, int *sum);

int main(int argc, char **argv) {

  if (argc != 3) {
    exit(EXIT_FAILURE);
  }

  int a = (int)strtol(argv[1], (char **)NULL, 10);
  int b = (int)strtol(argv[2], (char **)NULL, 10);

  int (*oper[4])(int a, int b) = {add, mul, divi, sub};
  int sum;

  for(int i = 0; i < 4; i++) {
    perform_operation(oper[i], &a, &b, &sum);
    printf("\noper[%d] = %d", i, sum);
  }

  return 0;
}

void perform_operation(int (*f)(int, int), 
    const int* a, const int* b, int *sum) {

  *sum = f(*a, *b);
}

int add(int a, int b) {
  return a + b;
}

int mul(int a, int b) {
  return a * b;
}

int divi(int a, int b) {
  return (int) (a / b);
}

int sub(int a, int b) {
  return a - b;
}

