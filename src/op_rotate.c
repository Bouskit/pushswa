/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 21:58:22 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/25 17:50:23 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	rotate(t_ps_list **stack)
{
	t_ps_list	*tmp;
	t_ps_list	*last;

	if (!stack || !(*stack) || !(*stack)->next)
		return ;
	tmp = *stack;
	*stack = (*stack)->next;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	tmp->next = NULL;
	last->next = tmp;
}

void	rotate_a(t_ps_list **stack_a)
{
	rotate(stack_a);
	ft_putstr("ra\n");
}

void	rotate_b(t_ps_list **stack_b)
{
	rotate(stack_b);
	ft_putstr("rb\n");
}

void	rotate_a_and_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr("rr\n");
}
