/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:47:11 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/28 13:39:38 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*clone_array(t_num **pile, int total)
{
	t_num	*aux;
	int		*array;
	int		i;

	aux = *pile;
	array = malloc(sizeof(int) * total);
	i = 0;
	while (aux)
	{
		array[i] = aux->content;
		i++;
		aux = aux->next;
	}
	return (array);
}

int	*array_sorted(int *array, int total)
{
	int	aux;
	int	i;
	int	k;

	i = 0;
	while (i < total)
	{
		k = i + 1;
		while (k < total)
		{
			if (array[i] > array[k])
			{
				aux = array[i];
				array[i] = array[k];
				array[k] = aux;
			}
			k++;
		}
		i++;
	}
	return (array);
}
