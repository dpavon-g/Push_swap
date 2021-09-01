/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:31:05 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/17 17:31:06 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	move_fiveh(int *sort_arr, t_values *cont, t_num **pilea, t_num **pileb)
{
	int	*array;
	int	chunk;
	int	conter;

	cont->flag = -1;
	chunk = 0;
	array = clone_array(pilea, cont);
	while (chunk < 11)
	{
		conter = 0;
		while (conter < cont->columns)
		{
			where_is_number(array, sort_arr, cont, chunk);
			up_down(array, cont, pilea, pileb);
			array = clone_array(pilea, cont);
			cont->total--;
			conter++;
		}
		chunk++;
	}
	while (*pilea)
	{
		cont->movements += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
}

void	separate_fiveh(t_values *cont, int *array, t_num **pila, t_num **pilb)
{
	int		*sort_array;

	cont->columns = cont->total / 11;
	sort_array = array_sorted(array, cont);
	move_fiveh(sort_array, cont, pila, pilb);
}

void	sort_fiveh(t_num **pilea, t_num **pileb, t_values *cont, int *sort_arr)
{
	int	*array;
	int	i;

	while (cont->total > 0)
	{
		i = 0;
		array = clone_array(pileb, cont);
		where_is_num2(array, sort_arr[cont->total - 1], cont);
		if (cont->flag == 1)
		{
			while (i < cont->position)
			{
				cont->movements += ra_rb(pileb);
				ft_printf("rb\n");
				i++;
			}
		}
		else if (cont->flag == 2)
		{
			while (i <= cont->position)
			{
				cont->movements += rra_rrb(pileb);
				ft_printf("rrb\n");
				i++;
			}
		}
		cont->movements += pa_pb(pileb, pilea);
		ft_printf("pa\n");
		cont->total--;
	}
}

int	order_fiveh(t_num **pilea, t_num **pileb, int total)
{
	t_values	content;
	int			*array;
	int			*sort_array;
	t_num		*auxb;

	auxb = *pileb;
	auxb++;
	ft_bzero(&content, sizeof(content));
	content.total = total;
	array = clone_array(pilea, &content);
	separate_piles(&content, array, pilea, pileb);
	content.total = total;
	sort_array = array_sorted(array, &content);
	sort_fiveh(pilea, pileb, &content, sort_array);
	free(array);
	return (content.movements);
}
