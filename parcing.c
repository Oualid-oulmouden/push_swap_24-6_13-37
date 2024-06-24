/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parcing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ooulmoud <ooulmoud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 17:44:39 by ooulmoud          #+#    #+#             */
/*   Updated: 2024/06/23 21:34:23 by ooulmoud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	handle_alpha(char **str, int n)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	if (str == NULL || *str == NULL)
		return ;
	while (i <= n - 1)
	{
		j = 0;
		while (str[i][j])
		{
			if (str[i][j] >= 'a' && str[i][j] <= 'z')
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	handle_duplicate(char **str, int n)
{
	int	i;
	int	j;
	(void)n;

	i = 1;
	if (*str == NULL)
		return ;
	while (str[i])
	{
		j = i + 1;
		while (j < n)
		{
			if (ft_atoi(str[i]) == ft_atoi(str[j]))
			{
				printf("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

void	handle_max_min(char **str, int n)
{
	int	i;

	i = 1;
	if (str == NULL)
		return ;
	while (i < n - 1)
	{
		if (ft_atoi(str[i]) > (long)2147483647
			|| ft_atoi(str[i]) < (long)-2147483648)
		{
			printf("Error\n");
			exit(1);
		}
		i++;
	}
}

void	handle_stack(t_list *stack_a, int size_of_stacka)
{
	handle_alpha(str, n);
	handle_duplicate(str, n);
	handle_max_min(str, n);
}
