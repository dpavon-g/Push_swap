/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 03:41:18 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/21 11:37:36 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	bigger_than(t_num **pilea)
{
	t_num	*aux;
	int		num;

	num = 0;
	aux = *pilea;
	while (aux)
	{
		if (num < aux->content)
			num = aux->content;
		aux = aux->next;
	}
	aux = *pilea;
	while (aux)
	{
		if (num > aux->content)
			num = aux->content;
		aux = aux->next;
	}
	return (num);
}

void	put_on(t_num **pilea, t_num **pileb, int *moves)
{
	t_num	*aux;
	int		total;

	total = count_numbers(pileb);
	aux = *pileb;
	if (total == 2)
	{
		if (aux->content < aux->next->content)
		{
			moves += sa_sb(pileb);
			ft_printf("sb\n");
		}
	}
	while (count_numbers(pileb) != 0)
	{
		*moves += pa_pb(pileb, pilea);
		ft_printf("pa\n");
	}
}

int	order_five(t_num **pilea, t_num **pileb, int total)
{
	int		smaller;
	int		position;
	int		movements;
	t_num	*aux;

	movements = 0;
	while (total > 3)
	{
		position = 0;
		smaller = bigger_than(pilea);
		aux = *pilea;
		while (aux->content != smaller)
		{
			position++;
			aux = aux->next;
		}
		movements += cases_five(pilea, pileb, position, total);
		total = count_numbers(pilea);
	}
	movements += order_three(pilea);
	put_on(pilea, pileb, &movements);
	return (movements);
}
