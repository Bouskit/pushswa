/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_lst.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/23 16:29:31 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/25 17:51:07 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	ps_lstsize(t_ps_list *lst)
{
	t_ps_list	*tmp;
	int			i;

	tmp = lst;
	i = 0;
	while (tmp)
	{
		tmp = tmp->next;
		i++;
	}
	return (i);
}

t_ps_list	*ps_lstnew(int value)
{
	t_ps_list	*new;

	new = malloc(sizeof(t_ps_list));
	if (!new)
		return (NULL);
	new->index = 0;
	new->value = value;
	new->next = NULL;
	return (new);
}

void	ps_lstadd_back(t_ps_list **lst, t_ps_list *new)
{
	if (!lst || !new)
		return ;
	if (*lst)
		ps_lstlast(*lst)->next = new;
	else
		*lst = new;
}

t_ps_list	*ps_lstlast(t_ps_list *lst)
{
	t_ps_list	*tmp;

	if (!lst)
		return (NULL);
	tmp = lst;
	while (tmp->next)
		tmp = tmp->next;
	return (tmp);
}

void	ps_free(t_ps_list **head)
{
	t_ps_list	*tmp;

	while (*head)
	{
		tmp = *head;
		*head = (*head)->next;
		free(tmp);
	}
}
