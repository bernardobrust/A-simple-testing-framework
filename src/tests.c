#include "astf.h"

int fibonacci(const int n) {
  if (n <= 1) {
    return n;
  }
  return fibonacci(n - 1) + fibonacci(n - 2);
}

void test_suite1() {
  astf_start_test_suite("One");

  // Should pass
  astf_AE_int(fibonacci(0), 0);
  astf_AE_int(fibonacci(1), 1);
  astf_AE_int(fibonacci(2), 1);
  astf_AE_int(fibonacci(3), 2);
  astf_ANE_int(fibonacci(4), 100);
  astf_AE(fibonacci(5) == 5);
  astf_AE_int(fibonacci(6), 8);
  astf_AL_int(fibonacci(10), fibonacci(15));
  astf_AF(fibonacci(6) == fibonacci(9));

  void *null_pointer = NULL;
  astf_A_null(null_pointer);
  int fib6 = fibonacci(6);
  astf_AN_null(&fib6);

  // Should fail
  astf_AE_int(fibonacci(6), 69);
  astf_ANE_int(fibonacci(10), 55);
  astf_AE(fibonacci(5) != 5);
  astf_AL_int(fibonacci(15), fibonacci(10));
  astf_AF(fibonacci(6) != fibonacci(9));

  int fib8 = fibonacci(8);
  astf_A_null(&fib8);
  void *null_pointer2 = NULL;
  astf_AN_null(null_pointer2);

  astf_retrieve_results();
}

void test_suite2() {
  astf_start_test_suite("Two");

  void *null_pointer = NULL;
  astf_A_null(null_pointer);
  int fib6 = fibonacci(6);
  astf_AN_null(&fib6);

  astf_retrieve_results();
}

void test_suite3() {
  astf_start_test_suite("Three");

  int fib8 = fibonacci(8);
  astf_A_null(&fib8);
  void *null_pointer = NULL;
  astf_AN_null(null_pointer);

  astf_AF_float(0.1f, 0.1f);
  astf_AE_string("AbC12", "AbC12");
  astf_ANE_float(0.09f, 0.1f);
  astf_ANE_string("AbC69", "AbC12");

  astf_retrieve_results();
}

int main() {
  test_suite1();
  test_suite2();
  test_suite3();

  return 0;
}
