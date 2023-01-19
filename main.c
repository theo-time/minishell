/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 13:10:37 by teliet            #+#    #+#             */
/*   Updated: 2023/01/19 18:55:20 by theo             ###   ########.fr       */
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


int turn_off_special_chars() {
    struct termios old_termios, new_termios;

    // Get the current terminal attributes
    if (tcgetattr(STDIN_FILENO, &old_termios) < 0) {
        perror("tcgetattr");
        return 1;
    }
    
    // Copy the old attributes to the new attributes
    new_termios = old_termios;
    // new_termios.c_cc[VEOF] = '\x03'; // set ctrl+D ('\x03') as VINTR (ctrl+c)
    // new_termios.c_cc[VINTR] = '\x04'; // set ctrl+D as VINTR --> SIGINT
    //new_termios.c_cc[VQUIT] = '\x1a'; // disable VQUIT --> SIGQUIT normally associated with  ctrl+\
    term.c_cc[VSTART] = '\x1a'; // disable VSTART
    new_termios.c_cc[VSUSP] = '\x04' ;//'\x1A'; // 
    new_termios.c_iflag &= ~(IXON | IXOFF); // turn off IXON and IXOFF flow control flags
    // SIGQUIT to ^/ link is missing
    // todo : the terminal settings should be saved and set back at end of execution
    if (tcsetattr(STDIN_FILENO, TCSANOW, &new_termios) < 0) {
        perror("tcsetattr");
        return 1;
    }

    return 0;
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
    env_vars_list = get_env_vars(env);
    // display_env_vars(env_vars_list);

    turn_off_special_chars();
    if(!catch_user_signals())
        return(1);
    while(1)
    {
        // getcwd(prompt_msg, 100);
        // prompt_msg = strcat(prompt_msg,"$ ");
        // cmd = readline(prompt_msg);
        // print_list_str(lexer((char *)cmd));
        // add_history(cmd);
        // free(cmd);
    }
}