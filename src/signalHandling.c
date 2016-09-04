/**
 * @file signalHandling.c
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Implementations for signal handling setup functions, and signal
 * handling functions themselves.
 */

#include "signalHandling.h"
#include <signal.h>
#include <stdlib.h>

static void sigfpe_handle(int signal);
static void sigsegv_handle(int signal);

/**
 * @brief Initialises the signal handling functions for a child fork - the
 * process running actual tests.
 */
void child_signal_setup(void)
{
    signal(SIGFPE, sigfpe_handle);
    signal(SIGSEGV, sigsegv_handle);
}

/**
 * @brief Signal handler for  SIGFPE - Signal Floating-Point Exception
 *
 * Handles a floating point exception and exits the program.
 *
 * @param signal The signal being handled.
 */
static void sigfpe_handle(int signal)
{
    exit(EXIT_SIGFPE);
}

/**
 * @brief Signal handler for SIGSEGV - Signal Segmentation Violation
 *
 * Handles a segmentation violation and exits the program.
 *
 * @param signal The signal being handled.
 */
static void sigsegv_handle(int signal)
{
    exit(EXIT_SIGSEGV);
}
