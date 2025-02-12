/*
BSD 3-Clause License

Copyright (c) 2025, Bernardo Brust

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions are met:

1. Redistributions of source code must retain the above copyright notice, this
   list of conditions and the following disclaimer.

2. Redistributions in binary form must reproduce the above copyright notice,
   this list of conditions and the following disclaimer in the documentation
   and/or other materials provided with the distribution.

3. Neither the name of the copyright holder nor the names of its
   contributors may be used to endorse or promote products derived from
   this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// * A simple test framework (astf) for C

#define ASTF_MAX_TESTS 1000
#define ASTF_MAX_MESSAGE_SIZE 256

// Colors
#define astf_output_fail "\x1b[31m"
#define astf_output_pass "\x1b[32m"
#define astf_output_warn "\x1b[33m"
#define astf_output_info "\x1b[36m"
#define astf_output_normal "\x1b[0m"

#define ASTF_PASSED astf_output_pass "Test passed" astf_output_normal

// Test counters
static int astf_tests_to_run = 0;
static int astf_tests_finished = 0;
static int astf_tests_failed = 0;
static int astf_tests_passed = 0;

// * Test list
// ---------------------------------------------------------------
typedef struct astf_test_list_t astf_test_list_t, *add_test, *get_test_message;
struct astf_test_list_t {
  int size;
  int test_id[ASTF_MAX_TESTS];
  char *test_message[ASTF_MAX_TESTS];

  void (*add_test)(astf_test_list_t *list, char *message);
  char *(*get_test_message)(astf_test_list_t *list, int test_id);
};

void test_list_add_test(astf_test_list_t *list, char *message) {
  list->test_id[list->size] = list->size;
  list->test_message[list->size] = (char *)malloc(strlen(message) + 1);
  strcpy(list->test_message[list->size], message);
  list->size++;
}
char *test_list_get_test_message(astf_test_list_t *list, int test_id) {
  return list->test_message[test_id];
}

astf_test_list_t astf_init_test_list() {
  astf_test_list_t list;
  list.size = 0;
  list.add_test = test_list_add_test;
  list.get_test_message = test_list_get_test_message;
  return list;
}

// ---------------------------------------------------------------

// * Test suite TODO
// ---------------------------------------------------------------

// I already know implementing this is going to be a pain in the ass

// void astf_create_test_suite(char *name) {}

// ---------------------------------------------------------------

static astf_test_list_t astf_test_list;

static inline void astf_print_init_tests() {
  printf("\n");
  printf(astf_output_info "Running %d tests...", astf_tests_to_run);
  printf("\n");
}

static inline void astf_start_testing() {
  astf_test_list = astf_init_test_list();
  astf_print_init_tests();
}

static inline void astf_print_results() {
  printf(astf_output_info "Finished running %d tests\n", astf_tests_finished);

  // Print amount of tests passed and failed
  if (astf_tests_passed == astf_tests_to_run) {
    printf(astf_output_pass "All tests passed!\n");
  } else {
    printf(astf_output_pass "|> %d tests passed!\n", astf_tests_passed);
    printf(astf_output_fail "|> %d tests failed ;-;\n", astf_tests_failed);
    printf("\n");

    for (int i = 0; i < astf_test_list.size; i++) {
      char *message = astf_test_list.get_test_message(&astf_test_list, i);

      if (strcmp(message, ASTF_PASSED) != 0) {
        printf(astf_output_fail "|> %s\n", message);
      }

      // ! Never forget freedom
      free(message);
    }
  }
  printf(astf_output_normal "\n");
}

/*
The int is just a placeholder for now
I'll have to do generics later
*/

// ? 2 variable tests
// ---------------------------------------------------------------

// ? Equality test
static inline void astf_assert_equals(int a, int b) {
  bool failed = false;

  astf_tests_to_run++;
  if (a == b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len,
             astf_output_fail "Test %d failed, '%d' and '%d' are different",
             astf_tests_finished, a, b);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}

// ? Inequality test
static inline void astf_assert_not_equals(int a, int b) {
  bool failed = false;

  astf_tests_to_run++;
  if (a != b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len,
             astf_output_fail "Test %d failed, '%d' and '%d' are equal",
             astf_tests_finished, a, b);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}

// ? Greater than test
static inline void astf_assert_greater_than(int a, int b) {
  bool failed = false;

  astf_tests_to_run++;
  if (a > b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;
  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len,
             astf_output_fail
             "Test %d failed, '%d' is smaller or equal to '%d'",
             astf_tests_finished, a, b);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}

// ? Less than test
static inline void astf_assert_less_than(int a, int b) {
  bool failed = false;

  astf_tests_to_run++;
  if (a < b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len,
             astf_output_fail
             "Test %d failed, '%d' is greater than or equal to '%d'",
             astf_tests_finished, a, b);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}
// ---------------------------------------------------------------

// ? 1 variable tests
// ---------------------------------------------------------------

// ? Truth test
static inline void astf_assert_true(bool a) {
  bool failed = false;

  astf_tests_to_run++;
  if (a) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len, astf_output_fail "Test %d failed, value is false",
             astf_tests_finished);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}

// ? False test
static inline void astf_assert_false(int a) {
  bool failed = false;

  astf_tests_to_run++;
  if (!a) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len, astf_output_fail "Test %d failed, value is true",
             astf_tests_finished);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}

// ? Null test
static inline void astf_assert_null(void *a) {
  bool failed = false;

  astf_tests_to_run++;
  if (a == NULL) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len,
             astf_output_fail "Test %d failed, pinter '%p' is not null",
             astf_tests_finished, a);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}

// ? Non null test
static inline void astf_assert_not_null(void *a) {
  bool failed = false;

  astf_tests_to_run++;
  if (a != NULL) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
    failed = true;
  }
  astf_tests_finished++;

  if (failed) {
    char buffer[ASTF_MAX_MESSAGE_SIZE];
    unsigned long max_len = sizeof(buffer);
    snprintf(buffer, max_len,
             astf_output_fail "Test %d failed, pointer is null",
             astf_tests_finished);
    astf_test_list.add_test(&astf_test_list, buffer);
  } else {
    astf_test_list.add_test(&astf_test_list, ASTF_PASSED);
  }
}
// ---------------------------------------------------------------
