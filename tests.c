/**
 * @file tests.c
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Implementation of the functions directly related to testing.
 */

#include "units.h"

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
    // add the test to the framework
}

