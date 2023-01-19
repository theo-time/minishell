/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:10:37 by teliet            #+#    #+#             */
/*   Updated: 2023/01/17 17:42:15 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"


void    print_list_str(char **strs)
{
    int i;
    i = 0;
    if(!strs)
        return;
    while(strs[i])
    {
        printf("%s", strs[i]);
        printf("\n-------\n");
        i++;
    }
}

int     main(int argc, char **argv, char **env)
{
    (void) argc;
    (void) env;
    (void) argv;
    const char *prompt_msg = "prompt_msg_todo>";

    while(1)
    {
        print_list_str(lexer(readline(prompt_msg)));
    }
}