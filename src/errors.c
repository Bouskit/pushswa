/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 14:15:39 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/27 12:29:04 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	error_digit(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
	{
		i = 0;
	}
	while (av[i])
	{
		j = 0;
		if (av[i][0] == '-' || av[i][0] == '+')
			j++;
		if (!av[i][j])
			return (0);
		while (av[i][j])
		{
			if (!ft_isdigit(av[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	error_doubles(int ac, char *av[])
{
	int	i;
	int	j;

	i = 1;
	if (ac == 2)
	{
		i = 0;
	}
	while (av[i + 1])
	{
		j = i + 1;
		while (av[j])
		{
			if (ft_atoi(av[i]) == ft_atoi(av[j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	str_is_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != ' ' && str[i] != 9 && (str[i] < '0' || str[i] > '9'))
			return (0);
		i++;
	}
	return (1);
}

void	error_exit(t_ps_list **stack_a, t_ps_list **stack_b, char **tmp, int c)
{
	if (stack_a != NULL)
		ps_free(stack_a);
	if (stack_b != NULL)
		ps_free(stack_b);
	write(2, "Error\n", 6);
	if (c == 2)
		ft_free(tmp);
	exit(0);
}

void	*ft_free(char **str)
{
	int		i;

	i = -1;
	while (++i, str[i])
		free(str[i]);
	free(str);
	return (0);
}
