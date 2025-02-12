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

// A simple test framework (astf) for C

// Colors
#define astf_output_fail "\x1b[31m"
#define astf_output_pass "\x1b[32m"
#define astf_output_warn "\x1b[33m"
#define astf_output_info "\x1b[36m"
#define astf_output_normal "\x1b[0m"

// Test counters
static int astf_tests_to_run = 0;
static int astf_tests_finished = 0;
static int astf_tests_failed = 0;
static int astf_tests_passed = 0;

static inline void astf_print_init_tests() {
  printf("\n");
  printf(astf_output_info "Running %d tests...", astf_tests_to_run);
  printf("\n");
}

static inline void astf_print_results() {
  printf(astf_output_info "Finished running %d tests\n", astf_tests_finished);

  // Print amount of tests passed and failed
  if (astf_tests_passed == astf_tests_to_run) {
    printf(astf_output_pass "All tests passed!\n");
  } else {
    printf(astf_output_pass "%d |> tests passed!\n", astf_tests_passed);
    printf(astf_output_fail "%d |> tests failed ;-;\n", astf_tests_failed);
  }
  printf(astf_output_normal "\n");
}

/*
For now, just leave this as it is
I'll implement the "Test x failed, expected 'a', got 'b'" later

The int is just a placeholder for now
I'll have to do generics later
*/

// ? 2 variable tests
// ---------------------------------------------------------------

// ? Equality test
static inline void astf_assert_equals(int a, int b) {
  astf_tests_to_run++;
  if (a == b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}

// ? Inequality test
static inline void astf_assert_not_equals(int a, int b) {
  astf_tests_to_run++;
  if (a != b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}

// ? Greater than test
static inline void astf_assert_greater_than(int a, int b) {
  astf_tests_to_run++;
  if (a > b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}

// ? Less than test
static inline void astf_assert_less_than(int a, int b) {
  astf_tests_to_run++;
  if (a < b) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}
// ---------------------------------------------------------------

// ? 1 variable tests
// ---------------------------------------------------------------

// ? Truth test
static inline void astf_assert_true(int a) {
  astf_tests_to_run++;
  if (a) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}

// ? False test
static inline void astf_assert_false(int a) {
  astf_tests_to_run++;
  if (!a) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}

// ? Null test
static inline void astf_assert_null(int *a) {
  astf_tests_to_run++;
  if (a == NULL) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}

// ? Not null test
static inline void astf_assert_not_null(int *a) {
  astf_tests_to_run++;
  if (a != NULL) {
    astf_tests_passed++;
  } else {
    astf_tests_failed++;
  }
  astf_tests_finished++;
}
// ---------------------------------------------------------------
