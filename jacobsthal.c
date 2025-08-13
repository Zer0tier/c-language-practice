#include <stdio.h>
#include <stdlib.h>

int jacobsthal(int n) {
  int result = 0;

  if (n < 2)
    result = n;
  else {
    int n_minus_one = jacobsthal(n - 1);
    int n_minus_two = jacobsthal(n - 2);

    result = 2 * n_minus_two + n_minus_one;
  }

  return result;
}

int main(int argc, char *argv[]) {
  if (argc == 3) {
    int i, n = atoi(argv[1]), f, t, number_iterations = atoi(argv[2]);
    for (i = 0; i < number_iterations; i++) {
      f = jacobsthal(n);
    }
    printf("Jacobsthal(%d) = %d \n", n, f);
    return 0;
  } else {
    printf("Format: %s value number_iterations\n", argv[0]);
    return 1;
  }
}


/*
 if n = 3;
 int n_minus_one  = jacobsthal(2) = 2* jacobsthal (0) + jacobthal (1) = 1
 int n_minus_two = jacobsthal(1) = 1;
 result = 2 + 1;
 result = 3;
*/
