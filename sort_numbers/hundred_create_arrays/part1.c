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

#include "../../push_swap.h"

// int	number_of_chunk(t_values *content)
// {
// 	if (content->total % 5 == 0)
// 		return (content->chunks = 5);
// 	else if (content->total % 4 == 0)
// 		return (content->chunks = 4);
// 	else if (content->total % 3 == 0)
// 		return (content->chunks = 3);
// 	else if (content->total % 2 == 0)
// 		return (content->chunks = 2);
// 	else
// 		return (content->chunks = 1);
// }

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
		while (array[k])
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

// int	**separate_chunks(int *sort_array, t_values *cont)
// {
// 	int	**array_chunks;
// 	int	i;
// 	int	l;
// 	int	k;

// 	i = 0;
// 	cont->columns = cont->total / cont->chunks;
// 	array_chunks = (int **) malloc(sizeof(int *) * cont->chunks);
// 	while (i < cont->chunks)
// 		array_chunks[i++] = (int *) malloc(sizeof(int) * cont->columns);
// 	i = 0;
// 	l = 0;
// 	while (i < cont->total)
// 	{
// 		k = 0;
// 		while (k < cont->columns)
// 		{
// 			array_chunks[l][k] = sort_array[i];
// 			k++;
// 			i++;
// 		}
// 		l++;
// 	}
// 	return (array_chunks);
// }
