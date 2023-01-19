/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:13 by theo              #+#    #+#             */
/*   Updated: 2023/01/19 18:40:36 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void event_handler(int signum) {
    if(signum == SIGINT)
    {
        printf("Caught signal %d: Ctrl+C pressed\n", signum);
        //printf("Caught signal %d: Ctrl+C pressed\n", signum);
        on_ctrl_c();
    }
    else if(signum == EOF)
    {
        printf("Caught signal %d: Ctrl+D pressed\n", signum);
        //rl_on_new_line();
        //kill(getpid());
        // exit(0);
        on_ctrl_c();
    }
    else if(signum == SIGQUIT)
    {
        printf("Caught signal %d: Ctrl+\\ pressed\n", signum);
        //rl_on_new_line();
        //kill(getpid());
        // exit(0);
        on_ctrl_c();
    }
    else if(signum == SIGTSTP)
    {
        printf("Caught signal %d: Ctrl+D pressed\n", signum);
        //rl_on_new_line();
        //kill(getpid());
        // exit(0);
        on_ctrl_c();
    }
    // Perform any necessary processing or cleanup
}

void ignore_signal(int signum) {
    // Do nothing, ignore the signal
}

int catch_user_signals() {
    struct sigaction act;
    act.sa_handler = event_handler;
    sigemptyset(&act.sa_mask);
    act.sa_flags = 0;
    
    if (sigaction(SIGINT, &act, NULL) < 0) {
        perror("sigaction EOF");
        return 0;
    }

    if (sigaction(SIGTSTP, &act, NULL) < 0) {
        perror("sigaction SIGTSTP");
        return 0;
    }

    if (sigaction(SIGQUIT, &act, NULL) < 0) {
        perror("sigaction SIGQUIT");
        return 0;
    }
    
    // ignore all other signals

    // act.sa_handler = ignore_signal;
    // for (int i = 1; i < NSIG; ++i) {
    //     if (i != SIGINT && i != SIGTSTP) {
    //         if (sigaction(i, &act, NULL) < 0) {
    //             perror("sigaction");
    //             return 1;
    //         }
    //     }
    // }

    return 1;
}
