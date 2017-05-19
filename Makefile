# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rramirez <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/05/11 15:05:07 by rramirez          #+#    #+#              #
#    Updated: 2017/05/11 15:05:09 by rramirez         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME	=	gnl

CC		=	gcc

FLAG	=	-Wall -Wextra -Werror -g

SRCS	= 	get_next_line.c\
			main.c\

OBJ		=	${SRCS:.c=.o}

INCLUDE	=	-I ft_db.h -L ./libft -lft 

all: $(NAME)

$(OBJ):
	@$(CC) $(FLAG) -c $(SRCS)

$(NAME): $(OBJ)
	@make all -C libft
	@$(CC) $(FLAG) $(INCLUDE) $(OBJ) -o $(NAME)

clean:
	@make clean -C libft
	@/bin/rm -f $(OBJ)

fclean: clean
	@make fclean -C libft
	@/bin/rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean
