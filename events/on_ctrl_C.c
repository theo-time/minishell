/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_ctrl_C.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 14:30:13 by theo              #+#    #+#             */
/*   Updated: 2023/01/19 17:24:05 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"

void stop_child_processes() {
    // todo : Code to stop child processes
}

void on_ctrl_c()
{

    // line = read_line();
    stop_child_processes();
    //char* current_line = rl_line_buffer;
    printf("Hello");
    //write(STDIN_FILENO, "^C\n", 2);
    // exit(0);
    rl_replace_line("", 0);
    //rl_redisplay();
    rl_done = 1;
    rl_on_new_line ();
}