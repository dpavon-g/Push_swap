/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5_hundred.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:31:05 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/21 15:47:03 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	move_fiveh(int *sort_arr, t_values *cont, t_num **pilea, t_num **pileb)
{
	int	*array;
	int	chunk;
	int	conter;

	chunk = 0;
	array = clone_array(pilea, cont->total);
	while (chunk++ < 11)
	{
		conter = 0;
		while (conter < cont->columns)
		{
			where_is_number(array, sort_arr, cont, chunk);
			up_down(array, cont, pilea, pileb);
			free(array);
			array = clone_array(pilea, cont->total);
			cont->total--;
			conter++;
		}
	}
	free(array);
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
	sort_array = array_sorted(array, cont->total);
	cont->flag = -1;
	move_fiveh(sort_array, cont, pila, pilb);
}

int	move_rr(int position, t_num **pileb, int flag)
{
	int	i;
	int	movements;

	movements = 0;
	i = 0;
	if (flag == 1)
	{
		while (i < position)
		{
			movements += ra_rb(pileb);
			ft_printf("rb\n");
			i++;
		}
	}
	else if (flag == 2)
	{
		while (i <= position)
		{
			movements += rra_rrb(pileb);
			ft_printf("rrb\n");
			i++;
		}
	}
	return (movements);
}

void	sort_fiveh(t_num **pilea, t_num **pileb, t_values *cont, int *sort_arr)
{
	int	*array;

	while (cont->total > 0)
	{
		array = clone_array(pileb, cont->total);
		where_is_num2(array, sort_arr[cont->total - 1], cont);
		cont->movements += move_rr(cont->position, pileb, cont->flag);
		cont->movements += pa_pb(pileb, pilea);
		ft_printf("pa\n");
		cont->total--;
		free(array);
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
	array = clone_array(pilea, total);
	separate_fiveh(&content, array, pilea, pileb);
	content.total = total;
	sort_array = array_sorted(array, total);
	sort_fiveh(pilea, pileb, &content, sort_array);
	free(array);
	return (content.movements);
}
