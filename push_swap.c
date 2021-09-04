/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:54:17 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/04 20:14:03 by dpavon-g         ###   ########.fr       */
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
	char	**str;
	int		i;
	int		k;
	int		flag;

	i = 0;
	flag = 0;
	while (argv[i] && flag == 0)
	{
		k = 0;
		flag = find_not_space(argv[i]);
		if (flag == 0)
		{
			str = ft_split(argv[i++], ' ');
			while (str[k])
			{
				flag = filter_errors(str[k]);
				add_in_pile(pilea, ft_atoi(str[k]));
				free(str[k++]);
			}
			free(str);
		}
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
