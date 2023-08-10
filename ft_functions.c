/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:31:31 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 19:09:00 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_list **stack)
{
	t_list	*temp;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = *stack;
	temp = *stack;
	(*stack) = (*stack)->next;
	temp->next = NULL;
	write(1, "rb\n", 3);
}

void	ft_rra(t_list **stack)
{
	t_list	*temp;
	t_list	*save;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next)
	{
		if (temp->next->next == NULL)
			save = temp;
		temp = temp->next;
	}
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = *stack;
	save->next = NULL;
	*stack = temp;
	write(1, "rra\n", 4);
}

void	ft_rrb(t_list **stack)
{
	t_list	*temp;
	t_list	*save;

	if (*stack == NULL)
		return ;
	if ((*stack)->next == NULL)
		return ;
	temp = *stack;
	while (temp->next)
	{
		if (temp->next->next == NULL)
			save = temp;
		temp = temp->next;
	}
	temp = *stack;
	while (temp)
	{
		if (temp->next == NULL)
			break ;
		temp = temp->next;
	}
	temp->next = *stack;
	save->next = NULL;
	*stack = temp;
	write(1, "rrb\n", 4);
}
