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

#include <stdbool.h>

struct test;

struct test_framework {
    int test_count;
    struct test* tests;
};

struct test_framework new_framework(void);

#define add_test(frame, test) _add_test(frame, test, #test)

void _add_test(struct test_framework* frame, void (*test_function)(void),
               const char* test_function_name);

void run_suite(struct test_framework* frame);

#define assert_equal(x, y) _assert((x) == (y), __LINE__)

#define assert_inequal(x, y) _assert((x) != (y), __LINE__)

#define assert_true(x) _assert(x, __LINE__)

#define assert_false(x) _assert(!(x), __LINE__)

void _assert(bool pass, int number);

#endif //UNITS_UNITS_H
