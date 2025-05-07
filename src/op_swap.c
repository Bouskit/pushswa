/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:33:55 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/25 17:50:23 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	swap(t_ps_list *stack)
{
	int	temp;

	if (stack == NULL)
		return ;
	temp = stack->value;
	stack->value = stack->next->value;
	stack->next->value = temp;
	return ;
}

void	swap_a(t_ps_list **stack_a)
{
	swap(*stack_a);
	ft_putstr("sa\n");
}

void	swap_b(t_ps_list **stack_b)
{
	swap(*stack_b);
	ft_putstr("sb\n");
}

void	swap_a_and_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	swap(*stack_a);
	swap(*stack_b);
	ft_putstr("ss\n");
}
