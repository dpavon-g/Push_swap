/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:54:17 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/21 12:04:56 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_not_space(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ')
			return (0);
		i++;
	}
	return (1);
}

int	take_args(char **argv, t_num **pilea)
{
	char	**st;
	int		k;
	int		flag;

	flag = 0;
	while (*argv && flag == 0)
	{
		k = 0;
		flag = find_not_space(*argv);
		if (flag == 0)
		{
			st = ft_split(*argv, ' ');
			while (st[k])
			{
				flag = filter_errors(st[k]);
				if (ft_atoi(st[k]) < -2147483648 || ft_atoi(st[k]) > 2147483647)
					return (1);
				add_in_pile(pilea, ft_atoi(st[k]));
				free(st[k++]);
			}
			free(st);
		}
		argv++;
	}
	return (flag);
}

int	main(int argc, char **argv)
{
	t_num	*pilea;
	t_num	*pileb;
	int		flags;

	flags = 0;
	if (argc > 1)
	{
		pilea = NULL;
		pileb = NULL;
		flags = take_args(++argv, &pilea);
		if (flags == 1)
			ft_printf("Error\n");
		else
		{
			if (repeat_number(&pilea) == 1)
				ft_printf("Error\n");
		}
		if (flags == 0)
		{
			if (is_order(&pilea) == 1)
				to_sort(&pilea, &pileb);
		}
	}
	return (0);
}
