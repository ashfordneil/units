/**
 * @file types.h
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Type definitions and matching function prototypes for the relevant
 * types in the Units framework.
 */

#ifndef UNITS_TYPES_H
#define UNITS_TYPES_H

#include "units.h"

/**
 * @brief Enumeration of the possible statuses of a test.
 */
enum test_status {
    /// Test currently indeterminate, or not yet comleted.
    INDETERMINATE,
    /// Test has failed.
    FAILED,
    /// Test has passed.
    PASSED
};

/**
 * @brief The compilation of necessary information to describe a test.
 */
struct test {
    /// The status of the test.
    enum test_status status;
    /// The function that executes the test.
    void (*test_function)(void);
    /// The name of the function that executes the test.
    char* test_function_name;
    /// The number of dependencies for this test.
    int dependency_count;
    /// An array-list containing the dependencies for this test.
    struct test* dependencies;
};

void new_test(struct test* output, void (*test_function)(void),
        const char* test_function_name);

void delete_test(struct test* param);

void delete_framework(struct test_framework* frame);

#endif //UNITS_TYPES_H
