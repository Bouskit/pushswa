/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/24 14:36:30 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/27 12:29:57 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	find_biggest(t_ps_list *stack)
{
	int			biggest;
	t_ps_list	*tmp;

	biggest = -2147483647;
	tmp = stack;
	while (tmp)
	{
		if (tmp->index > biggest)
			biggest = tmp->index;
		tmp = tmp->next;
	}
	return (biggest);
}

int	already_done(t_ps_list **stack_a)
{
	t_ps_list	*tmp;

	tmp = *stack_a;
	while (tmp && tmp->next)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
