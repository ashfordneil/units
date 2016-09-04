/**
 * @file signalHandling.h
 *
 * @author neil
 * @date 4/09/16
 *
 * @brief Prototypes for signal handling setup functions.
 */

#ifndef UNITS_SIGNALHANDLING_H
#define UNITS_SIGNALHANDLING_H

#define EXIT_SIGSEGV 2
#define EXIT_SIGFPE 3

void child_signal_setup(void);

#endif //UNITS_SIGNALHANDLING_H
