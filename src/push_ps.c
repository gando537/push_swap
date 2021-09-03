/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:52:00 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/22 20:01:25 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	push_a_bis(t_pile *pile, t_stack *stackB)
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

void	push_a(t_pile *pile)
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
	push_a_bis(pile, stackB);
	pile->size_pa += 1;
	pile->size_pb -= 1;
	write(1, "pa\n", 3);
}

void	push_b_bis(t_pile *pile, t_stack *stackA)
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

void	push_b(t_pile *pile)
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
	push_b_bis(pile, stackA);
	pile->size_pb += 1;
	pile->size_pa -= 1;
	write(1, "pb\n", 3);
}
