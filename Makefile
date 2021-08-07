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

ifndef silent
.SILENT:
endif

CC = gcc
NAME = push_swap.a

SRCS = 	push_swap.c\
		manage_list/create_list.c\
		manage_list/edit_list.c\
		show_piles/show_piles.c\
		sort_numbers/sort_two_three.c\
		sort_numbers/to_sort.c\
		sort_numbers/three_number_cases.c\
		sort_numbers/sort_five.c\
		sort_numbers/five_number_cases.c\
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
	@cp $(LIB_NAME) $(NAME)
	@$(CC) $(SRCS) push_swap.a -o push_swap

clean:
	@make -C $(LIB_PATH) clean
	@rm -f $(OBJECTS)

fclean: clean
	@make -C $(LIB_PATH) fclean
	@rm -f $(NAME)
	@rm -f push_swap

com: $(NAME)
	@$(CC) $(SRCS) push_swap.a -o push_swap

re: fclean all
bonus: re
.PHONY:	all clean fclean re
