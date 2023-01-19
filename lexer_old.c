/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: teliet <teliet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 14:48:29 by rfouraul          #+#    #+#             */
/*   Updated: 2023/01/17 14:49:35 by teliet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*only work for ' ' as space*/

#include "minishell.h"

long	ft_error(char *msg)
{
	printf("%s", msg);
	return (0);
}

static int	ft_find(char *str, int start, char c)
{
	int	i;

	i = start;
	while (str[i])
	{
		if (str[i] == c)
			return (i);
		i++;
	}
	return (i);
}

static int	ft_tokens_size(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		while (line[i] && line[i] == ' ')
			i++;
		if (line[i] == '\"')
			i = ft_find(line, i + 1, '\"');
		else if (line[i] == '\'')
			i = ft_find(line, i + 1, '\'');
		else
			i = ft_find(line, i, ' ');
		if (i && line[i])
			count++;
		else
			break ;
	}
	return (count);
}

static char	*ft_token(char *line, int start, char end)
{
	char	*token;
	int		size;

	size = ft_find(line, start, end);
	token = (char *)malloc(sizeof(char) * size);
	if (!token)
		return (NULL);
	token[size] = 0;
	while (size-- >= 0)
		token[size] = line[start + size];
	return (token);
}

static char	*ft_find_token(char *line, int start)
{
	char	*token;
	int		i;

	i = start;
	while (line[i] && line[i] == ' ')
		i++;
	if (line[i] == '\"')
		token = ft_token(line, i + 1, '\"');
	else if (line[i] == '\'')
		token = ft_token(line, i + 1, '\'');
	else
		token = ft_token(line, i, ' ');
	return (token);
	// while (line[i] && line[i] == ' ')
	// 	i++;
	// if (line[i] == '\"' && ft_find(line, i + 1, '\"'))
	// 	token = ft_token(line, i + 1, '\"');
	// else if (line[i] == '\'' && ft_find(line, i + 1, '\''))
	// 	token = ft_token(line, i + 1, '\'');
	// else
	// 	token = ft_token(line, i, ' ');
	// return (token);
}

char	**lexer(char *line)
{
	char	**tokens;
	int		pos;
	unsigned int		i;

	tokens = (char **)malloc(sizeof(char *) * (ft_tokens_size(line) + 1));
	printf("size : %d \n", ft_tokens_size(line));
	if (!tokens)
		return ((char **) ft_error("Malloc"));
	pos = 0;
	i = 0;
	while (line[i])
	{
		tokens[pos] = ft_find_token(line, i);
		if (!tokens[pos])
		{
			//ft_free_tokens(tokens, pos);
			return ((char **) ft_error("Malloc"));
		}
		i += ft_strlen(tokens[pos]) + 1;
		printf("word n*%d : %s \n", pos, tokens[pos]);
		pos++;
	}
	printf("NULL pos : %d \n", pos);
	tokens[pos] = NULL;
	return (tokens);
}
