/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:21:47 by mdiallo           #+#    #+#             */
/*   Updated: 2021/05/31 17:09:08 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a_bisch(t_pile *pile, t_stack *stackB)
{
	if (!(*(pile->pa)))
	{
		*(pile->pa) = stackB;
		(*(pile->pa))->next = NULL;
	}
	else
	{
		stackB->next = *(pile->pa);
		(*(pile->pa))->previous = stackB;
		*(pile->pa) = stackB;
		(*(pile->pa))->previous = NULL;
	}
}

void	push_ach(t_pile *pile)
{
	t_stack	*stackB;

	stackB = *(pile->pb);
	if (!stackB)
		return ;
	if ((*(pile->pb))->next != NULL)
	{
		*(pile->pb) = (*(pile->pb))->next;
		(*(pile->pb))->previous = NULL;
	}
	else
		*(pile->pb) = NULL;
	push_a_bisch(pile, stackB);
	pile->size_pa += 1;
	pile->size_pb -= 1;
}

void	push_b_bisch(t_pile *pile, t_stack *stackA)
{
	if (!(*(pile->pb)))
	{
		*(pile->pb) = stackA;
		(*(pile->pb))->next = NULL;
	}
	else
	{
		stackA->next = *(pile->pb);
		(*(pile->pb))->previous = stackA;
		*(pile->pb) = stackA;
		(*(pile->pb))->previous = NULL;
	}
}

void	push_bch(t_pile *pile)
{
	t_stack	*stackA;

	stackA = *(pile->pa);
	if (!stackA)
		return ;
	if ((*(pile->pa))->next != NULL)
	{
		*(pile->pa) = (*(pile->pa))->next;
		(*(pile->pa))->previous = NULL;
	}
	else
		*(pile->pa) = NULL;
	push_b_bisch(pile, stackA);
	pile->size_pb += 1;
	pile->size_pa -= 1;
}
