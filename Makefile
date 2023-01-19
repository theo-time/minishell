# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: theo <theo@student.42.fr>                  +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/29 20:41:39 by teliet            #+#    #+#              #
#    Updated: 2023/01/19 14:02:34 by theo             ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = minishell

SRC = main.c lexer.c get_env_vars.c utils/remove_quotes.c \

CC = gcc

HEADERS = ./includes

LIBS = -Llibft -lft -L/usr/local/lib -I/usr/local/include -lreadline

OBJ = $(SRC:.c=.o)
OBJ_bonus = $(SRC_bonus:.c=.o)

all: ${NAME}
 
$(NAME): $(OBJ) $(HEADERS)
	$(CC) $(OBJ) $(LIBS) -I $(HEADERS) -o $(NAME)

#$(OBJ_bonus):$(SRC_bonus) $(HEADERS_bonus)
#	$(CC) -Wall -Wextra -Werror -I $(HEADERS_bonus) -c $< -o $@

debug: $(HEADERS) clean
	$(CC) $(SRC) $(LIBS) -I $(HEADERS) -g3 -o $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -I $(HEADERS) -c $< -o $@ 

clean:
	/bin/rm -f ${OBJ}
	/bin/rm -f ${OBJ_bonus}

fclean: clean
	/bin/rm -f ${NAME}

re: fclean all
