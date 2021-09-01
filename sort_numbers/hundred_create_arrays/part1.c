/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   part1.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:47:11 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/17 18:47:13 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*clone_array(t_num **pile, t_values *cont)
{
	t_num	*aux;
	int		*array;
	int		i;

	aux = *pile;
	array = malloc(sizeof(int) * cont->total);
	i = 0;
	while (aux)
	{
		array[i] = aux->content;
		i++;
		aux = aux->next;
	}
	return (array);
}

int	*array_sorted(int *array, t_values *cont)
{
	int	aux;
	int	i;
	int	k;

	i = 0;
	while (i < cont->total)
	{
		k = i + 1;
		while (k < cont->total)
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
