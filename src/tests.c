/**
 * @file tests.c
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Implementation of the functions directly related to testing.
 */

#include <stdlib.h>
#include "units.h"
#include "types.h"

/**
 * @brief Adds a test to the test framework.
 *
 * @param frame The framework that the test is being appended to.
 * @param test_function The function that performs the test.
 * @param test_function_name The name of that function, as a string.
 */
void _add_test(struct test_framework* frame, void (*test_function)(void),
        const char* test_function_name)
{
    int newIndex = frame->test_count;
    frame->test_count++;
    frame->tests = realloc(frame->tests, sizeof(struct test) *
            frame->test_count);
    new_test(frame->tests + newIndex, test_function, test_function_name);
}

