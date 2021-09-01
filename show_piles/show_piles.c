/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   show_piles.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:10:54 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/05 21:10:56 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	show_pile(t_num *pilea, t_num *pileb)
{
	while (pilea && pileb)
	{
		ft_printf("|%5d|", (int)pilea->content);
		ft_printf("|%5d|\n", (int)pileb->content);
		pilea = pilea->next;
		pileb = pileb->next;
	}
	if (pilea)
	{
		while (pilea)
		{
			ft_printf("|%5d|", (int)pilea->content);
			ft_printf("|     |\n");
			pilea = pilea->next;
		}
	}
	if (pileb)
	{
		while (pileb)
		{
			ft_printf("|     |");
			ft_printf("|%5d|\n", (int)pileb->content);
			pileb = pileb->next;
		}
	}
}
