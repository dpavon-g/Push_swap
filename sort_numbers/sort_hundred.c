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

/*
	Tengo que encontrar un numero de chunk desde arriba
	luego tengo que encontrar otro numero de chunk desde abajo
	Compruebo cual es el que me pilla mas cerca
	y el que me pille mas cerca es el que tengo que subir o bajar.
*/

// int	find_in_chunk(int number, int *array, t_values *content)
// {
// 	int	i;

// 	i = 0;
// 	while (i < content->columns)
// 	{
// 		if (array[i] == number)
// 			return (1);
// 		i++;
// 	}
// 	return (0);
// }

void	move_chunks(int *sort_array, t_values *cont, t_num **pilea, t_num **pileb)
{
	int *array;
	int	i;
	int k;
	int	l;
	int	conter;
	int total;

	conter = 0;
	sort_array[0] = sort_array[0];
	array = clone_array(pilea, cont);
	cont->columns = cont->total / 5;
	total = cont->total - 1;
	i = 0;
	k = 0;
	l = 0;
	while (i < (cont->total - conter))
	{
		if (array[i] >= sort_array[0] && array[i] <= sort_array[cont->columns - 1])
		{
			l = 1;
			break;
		}
		if (array[total - i] >= sort_array[0] && array[total - i] <= sort_array[cont->columns - 1])
		{
			k = 1;
			break;
		}
		i++;
	}
	if (l == 1)
	{
		while ((*pilea)->content != array[i])
		{
			cont->movements += ra_rb(pilea);
			ft_printf("ra\n");
		}
		cont->movements += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
	if (k == 1)
	{
		while ((*pilea)->content != array[total - i])
		{
			cont->movements += rra_rrb(pilea);
			ft_printf("rra\n");
		}
		cont->movements += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
	free(array);
}

void	separate_piles(t_values *cont, int *array, t_num **pilea, t_num **pileb)
{
	int		*sort_array;
	int		i;

	i = 0;
	sort_array = array_sorted(array, cont);
	move_chunks(sort_array, cont, pilea, pileb);
}

int	order_hundred(t_num **pilea, t_num **pileb, int total)
{
	int			i;
	t_values	content;
	int			*array;
	t_num		*auxb;

	auxb = *pileb;
	i = 0;
	ft_bzero(&content, sizeof(content));
	content.total = total;
	array = clone_array(pilea, &content);
	separate_piles(&content, array, pilea, pileb);
	free(array);
	return (content.movements);
}
