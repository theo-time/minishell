/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: theo <theo@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 17:14:50 by teliet            #+#    #+#             */
/*   Updated: 2023/01/19 14:07:14 by theo             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int		get_word_end(char *str, int start, char sep)
{
	int i  = start;

	while(str[i])
	{
		if(str[i] == sep)
			return(i);
		else if(str[i] == '\'' &&  sep != '\"')
			i = get_word_end(str, i + 1, '\'') + 1;
		else if(str[i] == '\"' && sep != '\'')
			i = get_word_end(str, i + 1, '\"') + 1;
		else 
			i++;
	}
	if(sep == ' ')
		return (i);
	else
	{
		printf("sep not found");
		return (-2);
	}
}

static int	count_elements(char *str)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (str[i])
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		// else if(str[i] == '\'')
		// 	i = get_word_end(str, i, '\'') + 1;
		// else if(str[i] == '\"')
		// 	i = get_word_end(str, i, '\"') + 1;
		else 
			i = get_word_end(str, i, ' ');
		if(i < 0)
			return (-1);
		count++;
	}
	return (count);
}


static char	*get_word(char *start, char sep)
{
	char	*word;
	char	*end;
	int		i;

	i = 0;
	end = &(start[get_word_end(start, 0, sep)]);
	word = malloc(end - start + sizeof(char));
	if (!word)
		return (NULL);
	while (&start[i] != end)
	{
		word[i] = start[i];
		i++;
	}
	word[i] = 0;
	return (word);
}

char	**trim_quotes(char **strs)
{
	int		i;

	i = 0;
	while(strs[i])
	{
		strs[i] = remove_quotes(strs[i]);
		i++;
	}
	return(strs);
}

char	**lexer(char const *str)
{
	char	**strs;
	int		count;
	int		i;
	int size = ft_strlen(str);
	int		nb_elems;

	nb_elems = 	count_elements((char *)str );
	if(nb_elems < 0 )
	{
		printf("\nError : quotes not closed\n");
		return (NULL);
	}
	strs = malloc(sizeof(char *) * (nb_elems + 1));
	printf("nb elems : %d\n", nb_elems );
	if (!strs)
		return (NULL);
	count = 0;
	i = 0;
	while (i < size)
	{
		if (str[i] == ' ')
		{
			i++;
			continue ;
		}
		// else if(str[i] == '\'')
		// {
		// 	strs[count] = get_word((char *) &str[i + 1], '\'');
		// 	i++;
		// }
		// else if(str[i] == '\"')
		// {
		// 	strs[count] = get_word((char *) &str[i + 1], '\"');
		// 	i++;
		// }
		else 
			strs[count] = get_word((char *) &str[i], ' ');
		// printf("Pos %d : word n*%d : %s \n", i, count, strs[count]);
		i += ft_strlen(strs[count]) + 1;
		count++;
	}
	strs[count] = NULL;
	return (trim_quotes(strs));
}
