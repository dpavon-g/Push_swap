/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   five_number_cases.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 07:02:50 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/07 07:02:51 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	cases3_five(t_num **pilea, t_num **pileb)
{
	int	moves;

	moves = 0;
	moves += sa_sb(pilea);
	ft_printf("sa\n");
	moves += pa_pb(pilea, pileb);
	ft_printf("pb\n");
	return (moves);
}

int	cases2_five(t_num **pilea, t_num **pileb, int position, int total)
{
	int	moves;

	moves = 0;
	if ((total == 4 && position == 2) || (position == 3 && total == 5))
	{
		moves += rra_rrb(pilea);
		ft_printf("rra\n");
		moves += rra_rrb(pilea);
		ft_printf("rra\n");
		moves += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
	else if (total == 5 && position == 2)
	{
		moves += rra_rrb(pilea);
		ft_printf("rra\n");
		moves += rra_rrb(pilea);
		ft_printf("rra\n");
		moves += rra_rrb(pilea);
		ft_printf("rra\n");
		moves += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
	return (moves);
}

int	cases_five(t_num **pilea, t_num **pileb, int position, int total)
{
	int	moves;

	moves = 0;
	if (position == 0)
	{
		moves += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
	else if (position == 1)
	{
		moves += cases3_five(pilea, pileb);
	}
	else if (position == 2 || (position == 3 && total == 5))
	{
		moves += cases2_five(pilea, pileb, position, total);
	}
	else if (position == 3 || position == 4)
	{
		moves += rra_rrb(pilea);
		ft_printf("rra\n");
		moves += pa_pb(pilea, pileb);
		ft_printf("pb\n");
	}
	return (moves);
}
