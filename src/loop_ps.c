/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:47 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/28 15:45:49 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	cmp_median(t_pile *pile, int n, int median, int pil)
{
	int		i;
	t_stack	*elem;

	i = 0;
	elem = _stack(pile, pil);
	while (elem && i < n)
	{
		if (pil == 1 && elem->content < median)
			return (true);
		if (pil == 2 && elem->content >= median)
			return (true);
		i++;
		elem = elem->next;
	}
	return (false);
}

t_bool	check_push(t_pile *pile, t_nb_pr *nb_pr, t_mp mp, t_stack *stack)
{
	if (mp.p == 2 && stack->content >= mp.m)
	{
		push_a(pile);
		nb_pr->nb_p++;
		return (true);
	}
	else if (mp.p == 1 && stack->content < mp.m)
	{
		push_b(pile);
		nb_pr->nb_p++;
		return (true);
	}
	return (false);
}

t_bool	pu_rotbis(t_pile *pile, t_nb_pr *nb_pr, t_mp mp, t_stack *stack)
{
	if (check_push(pile, nb_pr, mp, stack) == true)
		return (true);
	else if (mp.p == 1 && cmp_median(pile, mp.l, mp.m, mp.p) == true)
	{
		swap_rotate_a(pile);
		nb_pr->nb_r++;
		return (true);
	}
	else if (mp.p == 2 && cmp_median(pile, mp.l, mp.m, mp.p) == true)
	{
		swap_rotate_b(pile);
		nb_pr->nb_r++;
		return (true);
	}
	return (false);
}

t_nb_pr	push_or_rotate(t_pile *pile, int median, int len, int pil)
{
	t_mp	mp;
	t_nb_pr	nb_pr;
	int		i;
	t_stack	*stack;

	i = 0;
	nb_pr.nb_r = 0;
	nb_pr.nb_p = 0;
	mp.p = pil;
	mp.m = median;
	mp.l = len;
	while (i < len)
	{
		stack = _stack(pile, pil);
		if (!stack)
			return (nb_pr);
		if (pu_rotbis(pile, &nb_pr, mp, stack) == false)
			return (nb_pr);
		i++;
	}
	return (nb_pr);
}
