# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 18:01:15 by dpavon-g          #+#    #+#              #
#    Updated: 2021/09/28 13:41:15 by dpavon-g         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap

SRCS = 	push_swap.c\
		errors/errors.c\
		manage_list/create_list.c\
		manage_list/edit_list.c\
		show_piles/show_piles.c\
		sort_numbers/sort_two_three.c\
		sort_numbers/to_sort.c\
		sort_numbers/three_number_cases.c\
		sort_numbers/sort_five.c\
		sort_numbers/five_number_cases.c\
		sort_numbers/sort_hundred.c\
		sort_numbers/create_arrays/part1.c\
		sort_numbers/know_position/know_position.c\
		instructions/instructions00.c\
		instructions/instructions01.c\
		sort_numbers/sort_5_hundred.c\

OBJECTS = $(SRCS:.c=.o)
LIB_PATH = libft/
LIB_NAME = $(LIB_PATH)libft.a
INCLUDES = -I. -I$(LIB_PATH)
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIB_PATH)
	@$(CC) $(CFLAGS) $^ -L ./libft/ -l ft -o $@

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
