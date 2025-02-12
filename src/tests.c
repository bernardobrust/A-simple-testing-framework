#include <stdio.h>

#include "astf.h"

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  printf("Testing fibonacci sequence\n");

  astf_print_init_tests();

  // Should pass
  astf_assert_equals(fibonacci(0), 0);
  astf_assert_equals(fibonacci(1), 1);
  astf_assert_equals(fibonacci(2), 1);
  astf_assert_equals(fibonacci(3), 2);
  astf_assert_equals(fibonacci(4), 3);
  astf_assert_equals(fibonacci(5), 5);
  astf_assert_equals(fibonacci(6), 8);
  astf_assert_greater_than(fibonacci(10), 50);
  astf_assert_less_than(fibonacci(10), 69420000);

  // Should fail
  astf_assert_not_equals(fibonacci(10), 55);
  astf_assert_greater_than(fibonacci(10), 100);

  astf_print_results();

  return 0;
}
