/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lalgo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:28:15 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 19:15:47 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_100(t_list **stacka, t_list **stackb)
{
	int	i;
	int	k;
	int	j;

	i = 0;
	k = ft_lstsize(*stacka);
	if (k <= 100)
		j = 15;
	else if (k <= 500)
		j = 45;
	while (k)
	{
		if ((*stacka)->indice < i)
		{
			ft_push_b(stacka, stackb);
			i++;
			j++;
			k--;
		}
		else if ((*stacka)->indice < j)
		{
			ft_push_b(stacka, stackb);
			ft_rb(stackb);
			i++;
			j++;
			k--;
		}
		else
			ft_ra(stacka);
	}
}

int	get_max(t_list *stack)
{
	int	max;
	int	indice;
	int	j;

	max = 0;
	indice = 0;
	j = 0;
	if (!stack)
		return (0);
	max = stack->data;
	while (stack)
	{
		if (max < stack->data)
		{
			max = stack->data;
			indice = j;
		}
		stack = stack->next;
		j++;
	}
	return (indice);
}

void	ft_repush_a(t_list **stacka, t_list **stackb)
{
	int	size;
	int	indice;

	size = ft_lstsize(*stackb);
	while (size)
	{
		indice = get_max(*stackb);
		if (indice > size / 2)
		{
			while (get_max(*stackb) != 0)
				ft_rrb(stackb);
			ft_push_a(stacka, stackb);
		}
		else
		{
			while (get_max(*stackb) != 0)
				ft_rb(stackb);
			ft_push_a(stacka, stackb);
		}
		size = ft_lstsize(*stackb);
	}
}
