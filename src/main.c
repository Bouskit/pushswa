/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 15:40:17 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/27 15:16:38 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

/////// AJOOUTER LE FREEEEEEE DANS LES ERRORS ET C BONNNNN ////////

int	main(int ac, char *av[])
{
	t_ps_list	*stack_a;
	t_ps_list	*stack_b;
	char		**tmp;

	if (ac < 2 || av[1][0] == '\0')
		return (0);
	tmp = av;
	if (ac == 2)
		tmp = ft_split(av[1], ' ');
	if (!error_digit(ac, tmp) || !error_doubles(ac, tmp))
		error_exit(NULL, NULL, tmp, ac);
	stack_b = NULL;
	stack_a = fill_stack_a(ac, tmp);
	if (!stack_a)
		error_exit(&stack_a, &stack_b, tmp, ac);
	put_index(stack_a);
	choose_algo(&stack_a, &stack_b);
	ps_free(&stack_a);
	ps_free(&stack_b);
	if (ac == 2)
		ft_free(tmp);
	return (0);
}
