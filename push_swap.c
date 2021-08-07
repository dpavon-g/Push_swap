/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/31 20:54:17 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/07/31 20:54:18 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	filter_errors(char *str)
{
	int	tester;
	int	flag;

	flag = 0;
	tester = 0;
	while (str[tester])
	{
		if (!((str[tester] >= '0' && str[tester] <= '9') || (str[tester] >= '-'
					&& (str[tester + 1] >= '0' && str[tester + 1] <= '9'))))
			flag = 1;
		tester++;
	}
	return (flag);
}

int	take_args(char **argv, t_num **pilea)
{
	char	**str;
	int		num;
	int		i;
	int		k;
	int		flag;

	i = 0;
	flag = 0;
	while (argv[i])
	{
		k = 0;
		str = ft_split(argv[i], ' ');
		while (str[k])
		{
			flag += filter_errors(str[k]);
			num = ft_atoi(str[k]);
			add_in_pile(pilea, num);
			free(str[k]);
			k++;
		}
		free(str);
		i++;
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
			ft_printf("Error");
		else
			to_sort(&pilea, &pileb);
		show_pile(pilea, pileb);
	}
	return (0);
}
