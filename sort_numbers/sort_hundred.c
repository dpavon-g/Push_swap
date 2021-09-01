/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_hundred.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:31:05 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/01 15:53:37 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	}
	else if (cont->flag == 2)
	{
		while ((*pilea)->content != array[(cont->total - 1) - cont->position])
		{
			cont->movements += rra_rrb(pilea);
			ft_printf("rra\n");
		}
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
	move_chunks(sort_array, cont, pila, pilb);
}

void	where_is_num2(int *array, int number, t_values *cont)
{
	cont->position = 0;
	cont->flag = 0;
	while (cont->position < cont->total)
	{
		if (array[cont->position] == number)
			cont->flag = 1;
		else if (array[(cont->total - 1) - cont->position] == number)
			cont->flag = 2;
		if (cont->flag == 1 || cont->flag == 2)
			break ;
		cont->position++;
	}
}

void	sort_pileb(t_num **pilea, t_num **pileb, t_values *cont, int *sort_arr)
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
	sort_array = array_sorted(array, &content);
	sort_array[0] = sort_array[0];
	sort_pileb(pilea, pileb, &content, sort_array);
	free(array);
	return (content.movements);
}
