/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   edit_list.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dpavon-g <dpavon-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 21:10:42 by dpavon-g          #+#    #+#             */
/*   Updated: 2021/09/28 13:41:53 by dpavon-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_lstadd_front2(t_num **alst, t_num *new)
{
	new->next = *alst;
	*alst = new;
}

t_num	*ft_lstlast2(t_num *lst)
{
	if (!lst)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void	ft_lstadd_back2(t_num **lst, t_num *new)
{
	t_num	*temp;

	temp = NULL;
	if (lst)
	{
		temp = *lst;
		if (!temp)
			*lst = new;
		else
		{	
			temp = ft_lstlast2(*lst);
			temp->next = new;
		}
	}
}

void	add_in_pile(t_num **pile, int t_nume)
{
	t_num	*aux;

	aux = ft_lstnew2(t_nume);
	ft_lstadd_back2(pile, aux);
}
