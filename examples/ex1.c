/**
 * @file ex1.c
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Demonstration of signal handling in the unit test framework.
 */

#include "units.h"
#include <signal.h>

static void testOne(void);
static void testTwo(void);
static void testThree(void);
static void testFour(void);

int main(int argc, char** argv)
{
    struct test_framework frame = new_framework();
    add_test(&frame, testOne);
    add_test(&frame, testTwo);
    add_test(&frame, testThree);
    add_test(&frame, testFour);
    run_suite(&frame);
    return 0;
}

static void testOne(void)
{
    return;
}

static void testTwo(void)
{
    raise(SIGSEGV);
}

static void testThree(void)
{
    raise(SIGFPE);
}

static void testFour(void)
{
    raise(SIGPIPE);
}
