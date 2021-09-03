/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:25 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 21:13:04 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*find_min(t_stack **stack)
{
	t_stack	*val_min;
	t_stack	*tmp;

	if (!*stack)
		return (NULL);
	val_min = *stack;
	if ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			if (val_min->content > tmp->content)
				val_min = tmp;
			tmp = tmp->next;
		}
	}
	return (val_min);
}

t_stack	*find_max(t_stack **stack)
{
	t_stack	*val_max;
	t_stack	*tmp;

	if (!*stack)
		return (NULL);
	val_max = *stack;
	if ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			if (val_max->content < tmp->content)
				val_max = tmp;
			tmp = tmp->next;
		}
	}
	return (val_max);
}
t_stack	*find_next_min(t_stack **stack, int value_min)
{
	t_stack	*next_min;
	t_stack	*tmp;

	if (!*stack)
		return (NULL);
	next_min = *stack;
	if ((*stack)->next != NULL)
	{
		tmp = (*stack)->next;
		while (tmp)
		{
			if (next_min->content > tmp->content
				&& tmp->content > value_min)
				next_min = tmp;
			tmp = tmp->next;
		}
	}
	return (next_min);
}

void	find_pivot(t_pile *pile, t_stack *stack)
{
	t_stack	*min;
	int		val;
	int		i;

	val = 11;
	i = -1;
	pile->size_pa = size_stack(&stack);
	if (pile->size_pa >= 40 && pile->size_pa <= 300)
		val = (pile->size_pa / 43) + 4;
	else if (pile->size_pa < 40)
		val = 4;
	min = find_min(&stack);
	while (++i < (pile->size_pa / val))
		min = find_next_min(&stack, min->content);
	pile->pivot = min;
}
