/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:10:37 by teliet            #+#    #+#             */
/*   Updated: 2023/01/18 19:01:15 by teliet           ###   ########.fr       */
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

void display_env_vars(t_env_var *head) {
    t_env_var *current = head;

    while (current != NULL) {
        // printf("%s\n", current->key);
        printf("%s=%s\n", current->key, current->value);
        current = current->next;
    }
}

int     main(int argc, char **argv, char **env)
{
    (void) argc;
    (void) env;
    (void) argv;
    char *prompt_msg;
    char *cmd;
    t_env_var *env_vars_list;
    prompt_msg = (char*) malloc(100);
    prompt_msg = strcat(prompt_msg,"$ ");
    env_vars_list = get_env_vars(env);
    display_env_vars(env_vars_list);
    // HIST_ENTRY **the_history_list;
    // HISTORY_STATE *history;
    // using_history();
    // history = history_get_history_state();
    while(1)
    {
        getcwd(prompt_msg, 100);
        prompt_msg = strcat(prompt_msg,"$ ");
        cmd = readline(prompt_msg);
        print_list_str(lexer((char *)cmd));
        add_history(cmd);
        // history_set_history_state(history);
        //printf("first cmd : %p\n", history->entries);
        free(cmd);
    }
}