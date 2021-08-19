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

#include "../push_swap.h"

void	where_is_number(int *array, int *sort_arr, t_values *cont, int chunk)
{
	cont->position = 0;
	cont->flag = 0;
	if (chunk != 5)
	{
		while (cont->position < cont->total)
		{
			if (array[cont->position] >= sort_arr[chunk * cont->columns]
				&& array[cont->position]
				<= sort_arr[((chunk + 1) * cont->columns) - 1])
				cont->flag = 1;
			if (array[(cont->total - 1) - cont->position]
				>= sort_arr[chunk * cont->columns]
				&& array[(cont->total - 1) - cont->position]
				<= sort_arr[((chunk + 1) * cont->columns) - 1])
				cont->flag = 2;
			if (cont->flag == 1 || cont->flag == 2)
				break ;
			cont->position++;
		}
	}
}

void	up_down(int *array, t_values *cont, t_num **pilea, t_num **pileb)
{
	if (cont->flag == 1)
	{
		while ((*pilea)->content != array[cont->position])
		{
			cont->movements += ra_rb(pilea);
			ft_printf("ra\n");
		}
		array[cont->position] = cont->trash;
	}
	else if (cont->flag == 2)
	{
		while ((*pilea)->content != array[(cont->total - 1) - cont->position])
		{
			cont->movements += rra_rrb(pilea);
			ft_printf("rra\n");
		}
		array[(cont->total - 1) - cont->position] = cont->trash;
	}
	cont->movements += pa_pb(pilea, pileb);
	ft_printf("pb\n");
}

void	move_chunks(int *sort_arr, t_values *cont, t_num **pilea, t_num **pileb)
{
	int	*array;
	int	chunk;
	int	conter;

	cont->flag = -1;
	chunk = 0;
	array = clone_array(pilea, cont);
	while (chunk < 5)
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

void	separate_piles(t_values *cont, int *array, t_num **pila, t_num **pilb)
{
	int		*sort_array;

	cont->columns = cont->total / 5;
	sort_array = array_sorted(array, cont);
	cont->trash = sort_array[0] - 1;
	move_chunks(sort_array, cont, pila, pilb);
}

// void	sort_pileb(t_num **pilea, t_num **pilb, t_values *cont, int *sort_arr)
// {
// 	int	i;
// 	int	*array;

// 	i = 0;
// 	array = clone_array(pileb, cont);
// 	where_is_num2(array, sort_arr[con->total - 1]);
// }

int	order_hundred(t_num **pilea, t_num **pileb, int total)
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
	sort_array = array_sorted(array, cont);
	// sort_pileb(pila, pilb, &content, sort_array);
	free(array);
	return (content.movements);
}
