/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_15.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/29 20:03:59 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 21:05:27 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void 	loop_ra(t_pile *pile, int value)
{
	while (value > 0)
	{
		swap_rotate_a(pile);
		value -= 1;
	}
}

void 	loop_rra(t_pile *pile, int value)
{
	while (value > 0)
	{
		swap_rotate_reverse_a(pile);
		value -= 1;
	}
	swap_rotate_reverse_a(pile);
}

void 	loop_rb(t_pile *pile, int value)
{
	while (value > 0)
	{
		swap_rotate_b(pile);
		value -= 1;
	}
}

void 	loop_rrb(t_pile *pile, int value)
{
	while (value > 0)
	{
		swap_rotate_reverse_b(pile);
		value -= 1;
	}
	swap_rotate_reverse_b(pile);
}

void	lst_15(t_pile *pile, int size, int pil)
{
	int		nb_p;
	int 	len;
	t_stack *tmp;
	t_stack *min_max;

	nb_p = 0;
	while (size--)
	{
		
		tmp = _stack(pile, pil);
		if (pil == 1)
			min_max = find_min(pile->pa);
		else
			min_max = find_max(pile->pb);
		len = 0;
		while (tmp && tmp->content != min_max->content && len++)
			tmp = tmp->next;
		if (pil == 1)
		{
			if (size - len <= size / 2 + size % 2)
				loop_ra(pile, len);
			else
				loop_rra(pile, size - len);
		}
		else if (pil == 2)
		{
			if (size - len <= size / 2 + size % 2)
				loop_rb(pile, len);
			else
				loop_rrb(pile, size - len);
		}
		if (pil == 1)
			push_b(pile);
		else
			push_a(pile);
		nb_p++;
    }
	if (pil == 1)
		while (nb_p--)
			push_a(pile);
	else
		while (nb_p--)
			push_b(pile);
}
