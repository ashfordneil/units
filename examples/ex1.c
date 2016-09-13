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
static void testFive(void);
static void testSix(void);
static void testSeven(void);
static void testEight(void);

int main(int argc, char** argv)
{
    struct test_framework frame = new_framework();
    add_test(&frame, testOne);
    add_test(&frame, testTwo);
    add_test(&frame, testThree);
    add_test(&frame, testFour);
    add_test(&frame, testFive);
    add_test(&frame, testSix);
    add_test(&frame, testSeven);
    add_test(&frame, testEight);
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

static void testFive(void)
{
    assert_true(3 == 3);
    assert_false(3 == 3);
}

static void testSix(void)
{
    assert_false(3 == 4);
    assert_true(3 == 4);
}

static void testSeven(void)
{
    assert_inequal(3, 4);
    assert_equal(3, 4);
}

static void testEight(void)
{
    assert_equal(3, 3);
    assert_inequal(3, 3);
}
