/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove_quotes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 12:48:31 by theo              #+#    #+#             */
/*   Updated: 2023/01/19 14:18:02 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

#include <stdio.h>
#include <stdlib.h>

int count_non_quoted_chars(char *str) {
    int count = 0;
    int i = 0;
    int in_quote = 0;
    int in_double_quote = 0;
    while (str[i]) {
        if (!in_double_quote  && str[i] == '\'') {
            in_quote = !in_quote;
        } 
        else if (!in_quote  && str[i] == '\"') {
            in_double_quote = !in_double_quote;
        } 
        else {
            count++;
        }
        i++;
    }
    return count;
}

char *remove_quotes(char *str) {
    int i = 0;
    int j = 0;
    int in_quote = 0;
    int in_double_quote = 0;
    char *new_str = malloc(count_non_quoted_chars(str) * sizeof(char));
    while (str[i]) {
        if (!in_double_quote  && str[i] == '\'') {
            in_quote = !in_quote;
        } 
        else if (!in_quote  && str[i] == '\"') {
            in_double_quote = !in_double_quote;
        } 
        else {
            new_str[j++] = str[i];
        }
        i++;
    }
    new_str[j] = '\0';
    free(str);
    return new_str;
}
