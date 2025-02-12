# A simple test suite

## Warning

This project was developed in one day for personal goals

Do not expect this to be a viable testing framework

## Why?

This project aims to be a simple testing framework for C.

The others are unnecessarily complex.

## Goals

Build the simplest single header test framework for C possible.

Be usable for my other projects.

## Design

Simplicity over all.

ASTF offers a very minimal and easy to use testing infrastructure.

## Tests

Kind of hard to test a testing framework.

Examples should do the trick.

***

## Progress so far

[x] - Asserts

[x] - Test suites

[user made] - Run all / run suites

[x] - Colors

[user made] - Skips

## Tutorial

Create a ```void``` function with the name of your test suite.

Then, add ```astf_start_test_suite("");``` at the top of the function with the name of your test suite as the argument, and ```astf_retrieve_results();``` at the end to get the results.

In between, add ```astf_...()``` with the assert type and the data type of the arguments. a.k.a ```astf_AE_int(a, b)``` for "Asset equal for ints".

More examples available at src/tests.c
