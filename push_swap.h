/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bboukach <bboukach@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:34:19 by bboukach          #+#    #+#             */
/*   Updated: 2024/11/27 13:21:07 by bboukach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

//------------------------       LISTES    ---------------------------//

typedef struct t_ps_list
{
	int					value;
	int					index;
	struct t_ps_list	*next;
}						t_ps_list;

t_ps_list				*ps_lstnew(int value);
void					ps_lstadd_back(t_ps_list **lst, t_ps_list *new);
t_ps_list				*ps_lstlast(t_ps_list *lst);
int						ps_lstsize(t_ps_list *lst);

//------------------------  UTILS ------------------------//

void					ft_putstr(char *str);
int						find_biggest(t_ps_list *stack);
void					ps_free(t_ps_list **stack);
int						ft_strcmp(char *s1, char *s2);
void					*ft_free(char **str);
char					*ft_int_max(int j);

//----------------- OPERATIONS -------------//

void					swap(t_ps_list *stack);
void					swap_a(t_ps_list **stack_a);
void					swap_b(t_ps_list **stack_b);
void					swap_a_and_b(t_ps_list **stack_a, t_ps_list **stack_b);

void					rotate(t_ps_list **stack);
void					rotate_a(t_ps_list **stack_a);
void					rotate_b(t_ps_list **stack_b);
void					rotate_a_and_b(t_ps_list **stack_a,
							t_ps_list **stack_b);

void					rev_rotate(t_ps_list **stack);
void					rev_rotate_a(t_ps_list **stack_a);
void					rev_rotate_b(t_ps_list **stack_b);
void					rev_rotate_a_and_b(t_ps_list **stack_a,
							t_ps_list **stack_b);

void					push(t_ps_list **src, t_ps_list **dest);
void					push_a(t_ps_list **stack_b, t_ps_list **stack_a);
void					push_b(t_ps_list **stack_a, t_ps_list **stack_b);

//--------------------  INITIALISATION  ----------------------------//

void					split_check(int ac, char *av[]);
int						error_digit(int ac, char *av[]);
int						error_doubles(int ac, char *av[]);
void					error_exit(t_ps_list **stack_a, t_ps_list **stack_b,
							char **tmp, int c);

int						already_done(t_ps_list **stack_a);

void					put_index(t_ps_list *stack_a);
t_ps_list				*fill_stack_a(int ac, char *av[]);

int						str_is_digit(char *str);

//--------------------        ALGORITHM       -----------------------//

void					sort_three(t_ps_list **stack_a);
void					sort_five(t_ps_list **stack_a, t_ps_list **stack_b);

int						bit_length(int num);
void					radix(t_ps_list **stack_a, t_ps_list **stack_b);

void					choose_algo(t_ps_list **stack_a, t_ps_list **stack_b);
