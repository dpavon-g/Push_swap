/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   know_position.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:39:00 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/21 11:37:39 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	where_is_number(int *array, int *sort_arr, t_values *cont, int chunk)
{
	cont->position = 0;
	cont->flag = 0;
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
