/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:45 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/22 10:07:33 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# define TYPES "cspdiuxX%"
# define EXTRA ".0*-"

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>
# include "libft/libft.h"
# include "libft/ft_printf/libftprintf.h"

typedef struct s_num
{
	int				content;
	struct s_num	*next;
}	t_num;

typedef struct s_dates
{
	int	total;
	int	columns;
	int	movements;
	int	position;
	int	flag;
}	t_values;

t_num	*ft_lstnew2(int content);
void	ft_lstadd_front2(t_num **alst, t_num *new);
t_num	*ft_lstlast2(t_num *lst);
void	ft_lstadd_back2(t_num **lst, t_num *new);
void	add_in_pile(t_num **pile, int t_nume);
void	show_pile(t_num *pilea, t_num *pileb);
int		repeat_number(t_num **pilea);
int		is_order(t_num **pilea);
int		filter_errors(char *str);
void	to_sort(t_num **pilea, t_num **pileb);
int		order_two(t_num **pilea);
int		order_three(t_num **pilea);
int		order_five(t_num **pilea, t_num **pileb, int total);
int		cases_five(t_num **pilea, t_num **pileb, int position, int total);
int		cases2_five(t_num **pilea, t_num **pileb, int position, int total);
int		cases3_five(t_num **pilea, t_num **pileb);
int		order_hundred(t_num **pilea, t_num **pileb, int total);
int		sa_sb(t_num **pile);
int		pa_pb(t_num **pile1, t_num **pile2);
int		ra_rb(t_num **pile);
int		rra_rrb(t_num **pile);
int		ss(t_num **pilea, t_num **pileb);
int		rr(t_num **pilea, t_num **pileb);
int		rrr(t_num **pilea, t_num **pileb);
void	case1(t_num **pilea, int *movements);
void	case2(t_num **pilea, int *movements);
void	case3(t_num **pilea, int *movements);
void	case4(t_num **pilea, int *movements);
void	case5(t_num **pilea, int *movements);
int		count_numbers(t_num **pile);
int		*array_sorted(int *array, int total);
void	separate_piles(t_values *cont, int *array, t_num **pila, t_num **pilb);
int		*clone_array(t_num **pile, int total);
void	where_is_number(int *array, int *sort_arr, t_values *cont, int chunk);
void	up_down(int *array, t_values *cont, t_num **pilea, t_num **pileb);
void	separate_fiveh(t_values *cont, int *array, t_num **pila, t_num **pilb);
void	sort_fiveh(t_num **pilea, t_num **pileb, t_values *cont, int *sort_arr);
void	where_is_num2(int *array, int number, t_values *cont);
int		order_fiveh(t_num **pilea, t_num **pileb, int total);
int		move_rr(int position, t_num **pileb, int flag);
#endif
