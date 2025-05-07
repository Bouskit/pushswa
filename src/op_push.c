/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/21 16:09:21 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/25 17:50:23 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_ps_list **src, t_ps_list **dest)
{
	t_ps_list	*tmp;

	if (*src == NULL)
		return ;
	tmp = (*src)->next;
	(*src)->next = *dest;
	*dest = *src;
	*src = tmp;
}

void	push_a(t_ps_list **stack_b, t_ps_list **stack_a)
{
	push(stack_b, stack_a);
	ft_putstr("pa\n");
}

void	push_b(t_ps_list **stack_a, t_ps_list **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr("pb\n");
}
