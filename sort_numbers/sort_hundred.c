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
	
}

// void	move_chunks(int *sort_array, t_values *cont, t_num **pilea, t_num **pileb)
// {
// 	int *array;
// 	int	i;
// 	int	l;
// 	int	k;
// 	int	trash;
// 	int chunk;

// 	sort_array[0] = sort_array[0];
// 	array = clone_array(pilea, cont);
// 	trash = (sort_array[0] - 1);
// 	cont->columns = cont->total / 5;
// 	chunk = 0;
// 	// while (chunk < 5)
// 	// {
// 		k = 0;
// 		while (k < cont->total/5 && *pilea)
// 		{
// 			i = 0;
// 			l = 0;
// 			while (i < cont->total)
// 			{
// 				if (array[i] >= sort_array[chunk * cont->columns] && array[i] <= sort_array[((chunk + 1) * cont->columns) - 1])
// 				{
// 					l = 1;
// 					ft_printf("Mayor que: %d\n", sort_array[chunk * cont->columns]);
// 					ft_printf("Menor que: %d\n", sort_array[((chunk + 1) * cont->columns) - 1]);
// 					ft_printf("El numero encontrado: %d\n", array[i]);
// 					break;
// 				}
// 				if (array[(cont->total - 1) - i] >= sort_array[chunk * cont->columns] && array[(cont->total - 1) - i] <= sort_array[((chunk + 1) * cont->columns) - 1])
// 				{
// 					l = 2;
// 					break;
// 				}
// 				i++;
// 			}
// 			//ft_printf("Ha encontrado el numero: %d\nl vale: %d\n", array[i], l);
// 			if (l == 1)
// 			{
// 				while ((*pilea)->content != array[i])
// 				{
// 					cont->movements += ra_rb(pilea);
// 					ft_printf("ra\n");
// 				}
// 				array[i] = trash;
// 			}
// 			if (l == 2)
// 			{
// 				while ((*pilea)->content != array[(cont->total - 1) - i])
// 				{
// 					cont->movements += rra_rrb(pilea);
// 					ft_printf("rra\n");
// 				}
// 				array[(cont->total - 1) - i] = trash;
// 			}
// 			cont->movements += pa_pb(pilea, pileb);
// 			ft_printf("pb\n");
// 			k++;
// 		}
// 	// 	chunk++;
// 	// }
// 	ft_printf("Mas chico %d\n", sort_array[0]);
// 	// while(*pilea)
// 	// {
// 	// 	cont->movements += pa_pb(pilea, pileb);
// 	// 	ft_printf("pb\n");
// 	// }
// 	free(array);
// }

void	separate_piles(t_values *cont, int *array, t_num **pilea, t_num **pileb)
{
	int		*sort_array;

	sort_array = array_sorted(array, cont);
	move_chunks(sort_array, cont, pilea, pileb);
}

int	order_hundred(t_num **pilea, t_num **pileb, int total)
{
	t_values	content;
	int			*array;
	t_num		*auxb;

	auxb = *pileb;
	auxb++;
	ft_bzero(&content, sizeof(content));
	content.total = total;
	array = clone_array(pilea, &content);
	separate_piles(&content, array, pilea, pileb);
	free(array);
	return (content.movements);
}
