/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 16:25:35 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/04 20:00:27 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	filter_errors(char *str)
{
	int	tester;
	int	flag;

	flag = 0;
	tester = 0;
	while (str[tester])
	{
		if (!((str[tester] >= '0' && str[tester] <= '9') || (str[tester] == '-'
					&& (str[tester + 1] >= '0' && str[tester + 1] <= '9'))))
			flag = 1;
		if (flag == 1)
			break ;
		tester++;
	}
	return (flag);
}

int	repeat_number(t_num **pilea)
{
	int	*array;
	int	total;
	int	flag;
	int	i;

	i = 0;
	flag = 0;
	total = count_numbers(pilea);
	array = array_sorted(clone_array(pilea, total), total);
	while (i < total)
	{
		if (array[i] == array[i + 1])
		{
			flag = 1;
			break ;
		}
		i++;
	}
	return (flag);
}

int	is_order(t_num **pilea)
{
	t_num	*aux;
	int		flag;

	aux = *pilea;
	flag = 0;
	while ((*pilea)->next)
	{
		if ((*pilea)->content < (*pilea)->next->content)
			flag = 0;
		else
		{
			flag = 1;
			break ;
		}
		(*pilea) = (*pilea)->next;
	}
	*pilea = aux;
	return (flag);
}
