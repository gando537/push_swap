/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:52:18 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 16:00:33 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	mini_atoi(char *s, long *n, t_stack **stack, t_pile *pile)
{
	int	neg;

	neg = 1;
	if (*s == '-' && *(s + 1) >= '0' && *(s + 1) <= '9')
	{
		neg = -1;
		s++;
	}
	while (*s)
	{
		if (*s >= '0' && *s <= '9')
			*n = 10 * *n + (*s++ - '0');
		else
			all_free(pile, stack, "");
		if (*n > INT_MAX || *n < INT_MIN)
			all_free(pile, stack, "");
	}
	*n *= neg;
}

int	mini_atoi_bis(char *s, long *n, t_stack **stack, t_pile *pile)
{
	int	ret;
	int	neg;

	neg = 1;
	ret = 0;
	if (*s == '-' && *(s + 1) >= '0' && *(s + 1) <= '9')
	{
		neg = -1;
		ret++;
		s++;
	}
	while (*s && *s != ' ')
	{
		if (*s >= '0' && *s <= '9')
			*n = 10 * *n + (*s++ - '0');
		else
			all_free(pile, stack, "");
		if (*n > INT_MAX || *n < INT_MIN)
			all_free(pile, stack, "");
		ret++;
	}
	*n *= neg;
	return (ret);
}

void	push_back_stack(t_stack **stack, t_stack *new)
{
	t_stack		*p_stack;

	if (!stack || !new)
		return ;
	if (!(*stack))
	{
		*stack = new;
		return ;
	}
	p_stack = *stack;
	while (p_stack->next != NULL)
		p_stack = p_stack->next;
	p_stack->next = new;
	new->previous = p_stack;
}

t_stack	*push_front_stack(t_stack **stack, int val)
{
	t_stack	*new;

	new = ft_new_elm(val);
	if (*stack)
	{
		(*stack)->previous = new;
		new->next = *stack;
	}
	return (new);
}

int	size_stack(t_stack **stack)
{
	int		size;
	t_stack	*tmp;

	size = 0;
	tmp = *stack;
	while (tmp)
	{
		size++;
		tmp = tmp->next;
	}
	return (size);
}
