/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:57:35 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/25 18:04:38 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	bit_length(int num)
{
	int	len;

	len = 0;
	while (num > 0)
	{
		num >>= 1;
		len++;
	}
	return (len);
}

void	sort_three(t_ps_list **stack_a)
{
	int	biggest;

	biggest = find_biggest(*stack_a);
	if ((*stack_a)->index == biggest)
		rotate_a(stack_a);
	else if ((*stack_a)->next->index == biggest)
		rev_rotate_a(stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	sort_five(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	size;

	size = ps_lstsize(*stack_a);
	while (size > 0)
	{
		if ((*stack_a)->index == 0 || (*stack_a)->index == 1)
			push_b(stack_a, stack_b);
		else
			rotate_a(stack_a);
		size--;
	}
	sort_three(stack_a);
	push_a(stack_b, stack_a);
	push_a(stack_b, stack_a);
	if ((*stack_a)->index > (*stack_a)->next->index)
		swap_a(stack_a);
}

void	radix(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	i;
	int	j;
	int	count;
	int	bit_size;

	count = ps_lstsize(*stack_a);
	bit_size = bit_length(count);
	i = 0;
	while (i < bit_size)
	{
		j = 0;
		while (j < count)
		{
			if (((*stack_a)->index >> i) & 1)
				rotate_a(stack_a);
			else
				push_b(stack_a, stack_b);
			j++;
		}
		while (*stack_b)
			push_a(stack_b, stack_a);
		i++;
	}
}

void	choose_algo(t_ps_list **stack_a, t_ps_list **stack_b)
{
	int	count;

	count = ps_lstsize(*stack_a);
	if (!already_done(stack_a) && count <= 3)
		sort_three(stack_a);
	else if (!already_done(stack_a) && count <= 5)
		sort_five(stack_a, stack_b);
	else if (!already_done(stack_a) && count > 5)
		radix(stack_a, stack_b);
	else
		return ;
}
