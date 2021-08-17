/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pavon <pavon@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/07 16:35:45 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/07/21 18:21:02 by pavon            ###   ########.fr       */
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

typedef struct nodo
{
	int				content;
	struct nodo		*next;
}	t_num;

typedef struct s_dates
{
	int	total;
	int	columns;
	int	movements;
}	t_values;

t_num	*ft_lstnew2(int content);
void	ft_lstadd_front2(t_num **alst, t_num *new);
t_num	*ft_lstlast2(t_num *lst);
void	ft_lstadd_back2(t_num **lst, t_num *new);
void	add_in_pile(t_num **pile, int t_nume);
void	show_pile(t_num *pilea, t_num *pileb);
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

//int		number_of_chunk(t_values *content);
int		*array_sorted(int *array, t_values *cont);
//int		**separate_chunks(int *sort_array, t_values *cont);
void	separate_piles(t_values *cont, int *array, t_num **pilea, t_num **pileb);
int		*clone_array(t_num **pile, t_values *cont);

#endif