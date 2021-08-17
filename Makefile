# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pavon <pavon@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/04/07 18:01:15 by dpavon-g          #+#    #+#              #
#    Updated: 2021/05/23 21:25:08 by pavon            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
NAME = push_swap

SRCS = 	push_swap.c\
		manage_list/create_list.c\
		manage_list/edit_list.c\
		show_piles/show_piles.c\
		sort_numbers/sort_two_three.c\
		sort_numbers/to_sort.c\
		sort_numbers/three_number_cases.c\
		sort_numbers/sort_five.c\
		sort_numbers/five_number_cases.c\
		sort_numbers/sort_hundred.c\
		sort_numbers/hundred_create_arrays/part1.c\
		instructions/instructions00.c\
		instructions/instructions01.c\

OBJECTS = $(SRCS:.c=.o)
LIB_PATH = libft/
LIB_NAME = $(LIB_PATH)libft.a
INCLUDES = -I. -I$(LIB_PATH)
CFLAGS = -Wall -Wextra -Werror $(INCLUDES)

all: $(NAME)

$(NAME): $(OBJECTS)
	@make -C $(LIB_PATH)
	@$(CC) $(SRCS) -L ./libft/ -l ft -o $(NAME)

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)

re: fclean all

.PHONY:	all clean fclean re
