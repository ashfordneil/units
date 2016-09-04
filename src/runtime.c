/**
 * @file runtime.c
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Implementations of internal runtime functions.
 */

#include "runtime.h"
#include "signalHandling.h"
#include "units.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <stdlib.h>

/**
 * @brief Executes a test.
 *
 * @param test The test to be executed.
 */
void run_test(struct test* test)
{
    if (test->status != INDETERMINATE) {
        // test has already run
        return;
    }

    pid_t pid = fork();
    if (pid == 0) {
        // child process
        child_signal_setup();
        test->test_function();
        _exit(EXIT_SUCCESS);
    }
    // parent process
    int status;
    waitpid(pid, &status, 0);

    if (!WIFEXITED(status)) {
        // something has gone horribly wrong
        return;
    }

    switch (WEXITSTATUS(status)) {
        case EXIT_SUCCESS:
            test->status = PASSED;
            break;
        case EXIT_FAILURE:
            test->status = FAILED;
            break;
        case EXIT_SIGSEGV:
            printf("\tTest '%s' Failed with signal SIGSEGV\n",
                    test->test_function_name);
            test->status = FAILED;
            break;
        case EXIT_SIGFPE:
            printf("\tTest '%s' Failed with signal SIGFPE\n",
                    test->test_function_name);
            test->status = FAILED;
            break;
        default:
            test->status = INDETERMINATE;
    }
}

/**
 * @brief Executes the running of a test suite.
 *
 * @param frame The test framework / suite to run.
 */
void run_suite(struct test_framework* frame)
{
    for (int i = 0; i < frame->test_count; ++i) {
        struct test* test = &frame->tests[i];
        printf("Running Test: %s\n", test->test_function_name);
        run_test(test);
        printf("\tTest Status: ");
        switch (test->status) {
            case INDETERMINATE:
                printf("Indeterminate.\n");
                break;
            case FAILED:
                printf("Failed.\n");
                break;
            case PASSED:
                printf("Passed.\n");
                break;
        }
    }
}
