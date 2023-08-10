/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asaouab <asaouab@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/10 17:12:34 by asaouab           #+#    #+#             */
/*   Updated: 2023/08/10 20:40:21 by asaouab          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*add_back(t_list *head, int nemb)
{
	t_list	*temp;
	t_list	*stock;

	temp = head;
	while (temp->next)
		temp = temp->next;
	stock = malloc(sizeof(t_list));
	stock->data = nemb;
	stock->next = NULL;
	temp->next = stock;
	return (head);
}

t_list	*linkedlist(t_list *newnode, int nemb)
{
	newnode = malloc(sizeof(t_list));
	if (newnode == NULL)
	{
		exit(1);
	}
	newnode->data = nemb; 
	newnode->next = NULL;
	return (newnode);
}

int	ft_lstsize(t_list *stack)
{
	int	i;

	i = 0;
	while (stack)
	{
		i++;
		stack = stack->next;
	}
	return (i);
}

// void leaks(void)
// {
// 	system("leaks push_swap");
// }
int	main(int argc, char **argv)
{
	// atexit(leaks);
	char	*join;
	char	**split;
	int		*arr;
	int		p;
	int		i;
	t_list	*stacka;
	t_list	*stackb;

	stackb = NULL;
	stacka = NULL;
	join = NULL;
	join = ft_strjoin(argc - 1, argv + 1, " ");
	split = ft_split(join, ' ');
	free(join);
	p = 0;
	ft_check(split);
	more_check(split);
	check_dup_num(split);
	stacka = linkedlist(stacka, ft_atoi(split[0]));
	i = 0;
	while (split[i++])
		p = i;
	if (p == 1 || argc == 1)
	{
		return (0);
	}
	i = 1;
	while (split[i])
	{
		stacka = add_back(stacka, ft_atoi(split[i]));
		i++;
	}
	//free split while
	arr = malloc(ft_lstsize(stacka) * sizeof(int));
	if (p == 2)
		ft_sort_two(&stacka);
	else if (p == 3)
		ft_sort_three(&stacka);
	else if (p == 4)
		ft_sort_four(stacka, stackb);
	else if (p == 5)
		ft_sortfive(stacka, stackb);
	else
	{
		ft_full_numbers(arr, stacka, p);
		arr = ft_sort_arr(arr, p);
		ft_add_indice(arr, stacka, p);
		ft_sort_100(&stacka, &stackb);
		ft_repush_a(&stacka, &stackb);
	}
	// free nodes
	// tmp = next
	// free(node)
	// node = tmp

	
	// while (stacka)
	// {
	// 	printf("%d\n", stacka->data);
	// 	stacka = stacka->next;
	// }
	return (0);
}
