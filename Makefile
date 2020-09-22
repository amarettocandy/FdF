# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: bmarlin <bmarlin@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/23 12:09:03 by bmarlin           #+#    #+#              #
#    Updated: 2020/03/03 12:55:43 by wscallop         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


FRAEMWORKS=-framework OpenGL -framework AppKit
FLAGS=-Werror -Wextra -Wall
NAME=fdf
SRC=src/*.c
INCLUDES=libft/libft.a minilibx_macos/libmlx.a

all:
	@make -C libft/ all
	@make -C minilibx_macos/ all
	gcc $(SRC) -o $(NAME) $(FLAGS) $(INCLUDES) $(FRAEMWORKS)

clean:
	@make -C libft/ clean
	@make -C minilibx_macos/ clean

fclean: clean
	/bin/rm -f $(NAME)
	@make -C libft/ fclean

re: fclean all

push:
	git add .
	git status
	git commit -m fdf
	git push
	
