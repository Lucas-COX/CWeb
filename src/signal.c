/*
 * =====================================================================================
 *
 *       Filename:  signal.c
 *
 *    Description:  Signal handlers for my http server
 *
 *        Version:  1.0
 *        Created:  21/03/2024 15:53:51
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  LUCAS COX (), 
 *   Organization:  
 *
 * =====================================================================================
 */

#include <signal.h>
#include <stdio.h>

extern int exited;

/**
 * @brief Handles the SIGINT for a clean exit
 *
 * @param[int] sig signal type
 */
void handle_sigint(int sig)
{
    printf("Received sigint, exiting properly...");
    exited = 1;
}

/**
 * @brief Sets up signal handling using sigaction
 *
 * @return -1 on error, 0 otherwise
 */
int setup_signal_handling()
{
    struct sigaction sa;

    sa.sa_handler = handle_sigint;
    sigemptyset(&sa.sa_mask);
    sa.sa_flags = SA_SIGINFO;
    return sigaction(SIGINT, &sa, NULL);
}
