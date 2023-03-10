/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:18:25 by teliet            #+#    #+#             */
/*   Updated: 2023/01/19 17:03:05 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 12:00:42 by teliet            #+#    #+#             */
/*   Updated: 2023/01/12 18:28:37 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include "libft.h"
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include <termios.h>

typedef struct s_env_var 
{
    char *key;
    char *value;
    struct s_env_var *next;
}   t_env_var;


char	    **lexer(char const *str);
t_env_var   *get_env_vars(char **env_list);

// Event Management
int     catch_user_signals();
void    on_ctrl_c();

// Utils
char *remove_quotes(char *str);

#endif