/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env_vars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:11:55 by teliet            #+#    #+#             */
/*   Updated: 2023/01/18 19:01:12 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "minishell.h"
# include "string.h"

t_env_var *get_env_vars(char **env_list) 
{
    t_env_var *head = NULL;
    t_env_var *current = NULL;
    char *key;
    char *value;
    char **key_value_pair;
    int i = 0;
    while(env_list[i]) {
        key_value_pair = ft_split(env_list[i], '=');
        key = key_value_pair[0];
        value = key_value_pair[1];
        //printf("%s=%s\n", key, getenv(key));

        if (head == NULL) {
            head = (t_env_var*)malloc(sizeof(t_env_var));
            head->key = key;
            head->value = value;
            head->next = NULL;
            current = head;
        } else {
            current->next = (t_env_var*)malloc(sizeof(t_env_var));
            current = current->next;
            current->key = key;
            current->value = value;
            current->next = NULL;
        }
        i++;
    }

    return head;
}