/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialisation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 22:20:28 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/27 13:11:10 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

char	*ft_int_max(int j)
{
	char	*int_max;

	int_max = "2147483647";
	if (j == 0)
		return (int_max);
	if (j == 1)
		int_max = "2147483648";
	return (int_max);
}

t_ps_list	*fill_stack_a(int ac, char *av[])
{
	int			i;
	int			j;
	t_ps_list	*tmp;
	t_ps_list	*stack_a;

	stack_a = NULL;
	i = 0;
	if (ac == 2)
		i = -1;
	while (av[++i])
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
			if (av[i][0] == '-')
				j++;
		if (ft_strlen(&av[i][j]) > 10 || (ft_strlen(&av[i][j]) == 10
				&& ft_strcmp(&av[i][j], ft_int_max(j)) > 0))
			error_exit(&stack_a, NULL, av, ac);
		tmp = ps_lstnew(ft_atoi(av[i]));
		if (!tmp)
			return (NULL);
		ps_lstadd_back(&stack_a, tmp);
	}
	return (stack_a);
}

void	put_index(t_ps_list *stack_a)
{
	t_ps_list	*biggest;
	t_ps_list	*tmp;
	int			size;

	tmp = stack_a;
	size = ps_lstsize(tmp) - 1;
	if (size < 0)
		return ;
	while (size >= 0)
	{
		biggest = NULL;
		tmp = stack_a;
		while (tmp)
		{
			if (!tmp->index && (biggest == NULL || tmp->value > biggest->value))
				biggest = tmp;
			tmp = tmp->next;
		}
		if (biggest)
			biggest->index = size;
		else
			break ;
		size--;
	}
}
