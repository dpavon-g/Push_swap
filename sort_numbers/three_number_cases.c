/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   three_number_cases.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 03:42:13 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/07 03:42:14 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	case1(t_num **pilea, int *movements)
{
	*movements += rra_rrb(pilea);
	ft_printf("RRA\n");
	*movements += sa_sb(pilea);
	ft_printf("SA\n");
}

void	case2(t_num **pilea, int *movements)
{
	*movements += rra_rrb(pilea);
	ft_printf("RRA\n");
}

void	case3(t_num **pilea, int *movements)
{
	*movements += sa_sb(pilea);
	ft_printf("SA\n");
	*movements += rra_rrb(pilea);
	ft_printf("RRA\n");
}

void	case4(t_num **pilea, int *movements)
{
	*movements += ra_rb(pilea);
	ft_printf("RA\n");
}

void	case5(t_num **pilea, int *movements)
{
	*movements += sa_sb(pilea);
	ft_printf("SA\n");
}
