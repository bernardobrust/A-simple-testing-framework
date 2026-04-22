# A simple test framework

## Mirror

This project was originaly in my gitlab. It was built one year ago.

## Warning

This project was developed in a few days for my personal goals.

Please do not expect this to be a viable testing framework.

## Why?

This project aims to be a simple testing framework for C.

The others are unnecessarily complex.

## Design

Simplicity over all.

ASTF offers a very minimal and easy to use testing infrastructure.

***

## Progress so far

[x] - Asserts

[x] - Test suites

[user made] - Run all / run suites

[x] - Colors

[user made] - Skips

## Tutorial (if you may call it that)

Copy the "astf.h" header to the location you put your projects libraries and include it where you want to test.

Create a ```void``` function with the name of your test suite.

Then, add ```astf_start_test_suite("");``` at the top of the function with the name of your test suite as the argument, and ```astf_retrieve_results();``` at the end to get the results.

In between, add ```astf_...()``` with the assert type and the data type of the arguments. a.k.a ```astf_AE_int(a, b)``` for "Asset equal for ints".

More examples available at src/tests.c
