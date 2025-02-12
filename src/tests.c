#include "astf.h"

int fibonacci(int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
  astf_start_testing();

  // Should pass
  astf_assert_equals(fibonacci(0), 0);
  astf_assert_equals(fibonacci(1), 1);
  astf_assert_equals(fibonacci(2), 1);
  astf_assert_equals(fibonacci(3), 2);
  astf_assert_not_equals(fibonacci(4), 100);
  astf_assert_true(fibonacci(5) == 5);
  astf_assert_equals(fibonacci(6), 8);
  astf_assert_less_than(fibonacci(10), fibonacci(15));
  astf_assert_false(fibonacci(6) == fibonacci(9));

  void *null_pointer = NULL;
  astf_assert_null(null_pointer);
  int fib6 = fibonacci(6);
  astf_assert_not_null(&fib6);

  // Should fail
  astf_assert_equals(fibonacci(6), 69);
  astf_assert_not_equals(fibonacci(10), 55);
  astf_assert_true(fibonacci(5) != 5);
  astf_assert_less_than(fibonacci(15), fibonacci(10));
  astf_assert_false(fibonacci(6) != fibonacci(9));

  int fib8 = fibonacci(8);
  astf_assert_null(&fib8);
  void *null_pointer2 = NULL;
  astf_assert_not_null(null_pointer2);

  astf_print_results();

  return 0;
}
