/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rev_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 15:45:57 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/25 17:50:23 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rev_rotate(t_ps_list **stack)
{
	t_ps_list	*last;
	t_ps_list	*second_last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	last = *stack;
	second_last = NULL;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	second_last->next = NULL;
	last->next = *stack;
	*stack = last;
}

void	rev_rotate_a(t_ps_list **stack_a)
{
	rev_rotate(stack_a);
	ft_putstr("rra\n");
}

void	rev_rotate_b(t_ps_list **stack_b)
{
	rev_rotate(stack_b);
	ft_putstr("rrb\n");
}

void	rev_rotate_a_and_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	rev_rotate(stack_a);
	rev_rotate(stack_b);
	ft_putstr("rrr\n");
}
