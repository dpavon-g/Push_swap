/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/07 03:41:25 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/08/07 03:41:28 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	order_two(t_num **pilea)
{
	int	num1;
	int	num2;

	num1 = (*pilea)->content;
	num2 = (*pilea)->next->content;
	if (num1 > num2)
	{
		sa_sb(pilea);
		ft_printf("sa\n");
		return (1);
	}
	return (0);
}

int	order_three(t_num **pilea)
{
	int		num1;
	int		num2;
	int		num3;
	int		movements;

	movements = 0;
	num1 = (*pilea)->content;
	num2 = (*pilea)->next->content;
	num3 = (*pilea)->next->next->content;
	if (num1 < num2 && num2 > num3 && num3 > num1)
		case1(pilea, &movements);
	else if (num1 < num2 && num2 > num3 && num3 < num1)
		case2(pilea, &movements);
	else if (num1 > num2 && num2 > num3 && num3 < num1)
		case3(pilea, &movements);
	else if (num1 > num2 && num2 < num3 && num3 < num1)
		case4(pilea, &movements);
	else if (num1 > num2 && num2 < num3 && num3 > num1)
		case5(pilea, &movements);
	return (movements);
}
