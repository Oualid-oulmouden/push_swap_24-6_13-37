/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_utils1.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulmoud <ooulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/09 10:11:26 by ooulmoud          #+#    #+#             */
/*   Updated: 2024/06/23 20:42:06 by ooulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_n(t_list *stack, int n)
{
	while (stack)
	{
		if (n == stack->content)
			return (1);
		stack = stack->next;
	}
	return (0);
}

void	free_stack(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}

int	add_to_stack(t_list **stack, char **ar)
{
	t_list	*node;
	int		tmp;
	int		i;

	node = NULL;
	i = 0;
	while (ar[i])
	{
		tmp = ft_atoi(ar[i]);
		if (check_n(*stack, tmp))
			return (1);
		node = ft_lstnew(tmp);
		if (!node)
			return (1);
		ft_lstadd_back(stack, node);
		i++;
	}
	return (0);
}

void	tree_sort(t_list **stack)
{
	if ((*stack)->content > ((t_list *)(*stack)->next)->content)
	{
		write(1, "sa\n", 3);
		swap_value_in_a(*stack);
	}
	else if (((t_list *)(*stack)->next)->content >
		((t_list *)((t_list *)(*stack)->next)->next)->content)
	{
		write(1, "rra\n", 4);
		retate_revers_a(stack);
	}
	else
		return ;
	tree_sort(stack);
}

void	free_stack1(t_list *lst)
{
	t_list	*temp;

	while (lst)
	{
		temp = lst->next;
		free(lst);
		lst = temp;
	}
}
