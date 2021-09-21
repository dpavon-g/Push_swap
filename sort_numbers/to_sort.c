/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 03:41:52 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/21 11:42:45 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_numbers(t_num **pile)
{
	t_num	*aux;
	int		total;

	aux = (*pile);
	total = 0;
	while (aux)
	{
		total++;
		aux = aux->next;
	}
	return (total);
}

void	to_sort(t_num **pilea, t_num **pileb)
{
	int	total;
	int	movements;

	movements = 0;
	total = count_numbers(pilea);
	if (total == 2)
		movements = order_two(pilea);
	else if (total == 3)
		movements = order_three(pilea);
	else if (total == 4 || total == 5)
		movements = order_five(pilea, pileb, total);
	else if (total > 5 && total <= 100)
		movements = order_hundred(pilea, pileb, total);
	else if (total >= 100)
		movements = order_fiveh(pilea, pileb, total);
	(void)movements;
}
