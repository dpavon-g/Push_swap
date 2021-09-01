/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions01.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:10:13 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/05 21:10:14 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rra_rrb(t_num **pile)
{
	t_num	*aux;
	int		i;

	if ((*pile))
	{
		i = 0;
		aux = *pile;
		while ((*pile)->next)
		{
			*pile = (*pile)->next;
			i++;
		}
		(*pile) = aux;
		while (i > 0)
		{
			ra_rb(pile);
			i--;
		}
	}
	return (1);
}

int	rrr(t_num **pilea, t_num **pileb)
{
	if (pilea)
		rra_rrb(pilea);
	if (pileb)
		rra_rrb(pileb);
	return (1);
}
