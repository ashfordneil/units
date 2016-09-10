/**
 * @file types.c
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Implementations of the type creators, and eventually destructors.
 */

#include "types.h"
#include "units.h"
#include <stdlib.h>
#include <string.h>

/**
 * @brief Creates a test struct, initialising its values appropriately.
 *
 * @param output The location to store the output.
 * @param test_function The function that executes the test.
 * @param test_function_name The name of the function that executes the test.
 */
void new_test(struct test* output, void (*test_function)(void),
        const char* test_function_name)
{
    if (output == NULL) {
        return;
    }
    output->status = INDETERMINATE;
    output->test_function = test_function;
    output->test_function_name = malloc(sizeof(char) *
            (1 + strlen(test_function_name)));
    strcpy(output->test_function_name, test_function_name);
    output->dependency_count = 0;
    output->dependencies = NULL;
}

/**
 * @brief Deletes a test struct, freeing all necessary memory.
 *
 * @param param The test struct to be deleted.
 */
void delete_test(struct test* param)
{
    if (param == NULL) {
        return;
    }

    if (param->test_function_name != NULL) {
        free(param->test_function_name);
    }

    if (param->dependencies) {
        free(param->dependencies);
    }
}


/**
 * @brief Creates and returns an empty test framework.
 *
 * @return The empty framework.
 */
struct test_framework new_framework(void)
{
    struct test_framework output;
    output.test_count = 0;
    output.tests = NULL;
    return output;
}

/**
 * @brief Deletes a test framework, freeing all necessary memory.
 *
 * @param frame The test framework to be deleted.
 */
void delete_framework(struct test_framework* frame)
{
    for (int i = 0; i < frame->test_count; ++i) {
        delete_test(&frame->tests[i]);
    }
    free(frame->tests);
}
