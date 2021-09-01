/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instructions00.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:10:07 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/05 21:10:09 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	sa_sb(t_num **pile)
{
	int		aux;

	if (*pile)
	{
		aux = (*pile)->content;
		(*pile)->content = (*pile)->next->content;
		(*pile)->next->content = aux;
		return (1);
	}
	return (0);
}

int	pa_pb(t_num **pile1, t_num **pile2)
{
	t_num	*t_number;
	t_num	*aux;
	int		p;

	if ((*pile1))
	{
		p = (*pile1)->content;
		t_number = ft_lstnew2(p);
		ft_lstadd_front2(pile2, t_number);
		aux = *pile1;
		if ((*pile1)->next)
			*pile1 = (*pile1)->next;
		else
			*pile1 = NULL;
		free(aux);
	}
	return (1);
}

int	ra_rb(t_num **pile)
{
	t_num	*aux;
	t_num	*t_number;
	int		n;

	if ((*pile)->next)
	{
		n = (*pile)->content;
		aux = *pile;
		*pile = (*pile)->next;
		free(aux);
		t_number = ft_lstnew2(n);
		ft_lstadd_back2(pile, t_number);
	}
	return (1);
}

int	ss(t_num **pilea, t_num **pileb)
{
	if (pilea)
		sa_sb(pilea);
	if (pileb)
		sa_sb(pileb);
	return (1);
}

int	rr(t_num **pilea, t_num **pileb)
{
	if (pilea)
		ra_rb(pilea);
	if (pileb)
		ra_rb(pileb);
	return (1);
}
