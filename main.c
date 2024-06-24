/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulmoud <ooulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 10:41:12 by ooulmoud          #+#    #+#             */
/*   Updated: 2024/06/23 21:35:47 by ooulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>

void	puch_not_lis(t_list **stack_a, t_list **stack_b)
{
	t_list	*lis1;
	t_list	*lis;

	lis1 = find_lis(*stack_a);
	while (ft_lstsize(lis1) != ft_lstsize(*stack_a))
	{
		lis = lis1;
		while (lis)
		{
			if (lis->content == (*stack_a)->content)
				break ;
			else if (!lis->next)
			{
				push_to_b(stack_a, stack_b);
				write(1, "pb\n", 3);
			}
			lis = lis->next;
		}
		retate_a(stack_a);
		write(1, "ra\n", 3);
	}
	free_stack1(lis);
	free_stack1(lis1);
}

int	free_memory1(char **s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		free(s[i]);
		i++;
	}
	free(s);
	return (0);
}

t_list	*split_space(char *av[], int ac)
{
	int		i;
	char	**tmp;
	t_list	*stack_a;

	i = 1;
	stack_a = NULL;
	while (i < ac)
	{
		tmp = ft_split(av[i], ' ');
		if (!tmp || !(*tmp))
			return (0);
		if (add_to_stack(&stack_a, tmp) == 1)
		{
			free_stack1(stack_a);
			free_memory1(tmp);
			return (stack_a);
		}
		free_memory1(tmp);
		i++;
	}
	return (stack_a);
}

int	check_tow_tree(t_list *stack_a)
{
	if (check_sort(stack_a))
	{
		free_stack1(stack_a);
		exit(0);
	}
	if (ft_lstsize(stack_a) == 2)
	{
		two_sort(stack_a);
		free_stack1(stack_a);
		exit(0);
	}
	if (ft_lstsize(stack_a) == 3)
	{
		tree_sort(&stack_a);
		free_stack1(stack_a);
		exit(0);
	}
	return (1);
}

int	main(int ac, char *av[])
{
	t_list	*stack_a;
	t_list	*stack_b;
	int		*t;
	int		*m;

	
	stack_b = NULL;
	stack_a = split_space(av, ac);
	handle_stack(stack_a, ft_lstsize(stack_a);
	while (stack_a) {
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	
	}
	exit(10);
	if (!stack_a)
		return (0);
	if(ft_lstsize(stack_a) <= 3)
		check_tow_tree(stack_a);
	sort(&stack_a, ft_lstsize(stack_a));
	puch_not_lis(&stack_a, &stack_b);
	while (ft_lstsize(stack_b))
	{
		t = stack_to_arry(stack_a, ft_lstsize(stack_a));
		m = get_bestmove(t, stack_b, ft_lstsize(stack_a), ft_lstsize(stack_b));
		make_themove(&stack_a, &stack_b, m);
		free(m);
		free(t);
	}
	sort(&stack_a, ft_lstsize(stack_a));
	free_stack1(stack_b);
	free_stack1(stack_a);
	system("leaks push_swap");
}
