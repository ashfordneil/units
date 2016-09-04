/**
 * @file units.h
 *
 * @author neil
 * @date 3/09/16
 *
 * @brief The external header file for Units, to be included by other programs
 */

#ifndef UNITS_UNITS_H
#define UNITS_UNITS_H

struct test;

/**
 * @brief A simple array-list that stores the tests in the framework.
 */
struct test_framework {
    /// The number of tests in the framework.
    int test_count;
    /// The array-list containing these tests.
    struct test* tests;
};

struct test_framework new_framework(void);

#define add_test(frame, test) _add_test(frame, test, #test)

void _add_test(struct test_framework* frame, void (*test_function)(void),
               const char* test_function_name);

void run_suite(struct test_framework* frame);

#endif //UNITS_UNITS_H
