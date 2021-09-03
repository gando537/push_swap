/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ps.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:52:08 by mdiallo           #+#    #+#             */
/*   Updated: 2021/05/31 19:18:45 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_b(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pb || !*(pile->pb) || !(*(pile->pb))->next)
		return ;
	temp = *(pile->pb);
	*(pile->pb) = (*(pile->pb))->next;
	temp->next = (*(pile->pb))->next;
	if (pile->size_pb > 2)
		temp->next->previous = temp;
	(*(pile->pb))->next = temp;
	temp->previous = *(pile->pb);
	(*(pile->pb))->previous = NULL;
	write(1, "sb\n", 3);
}

void	swap_a(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pa || !*(pile->pa) || !(*(pile->pa))->next)
		return ;
	temp = *(pile->pa);
	*(pile->pa) = (*(pile->pa))->next;
	temp->next = (*(pile->pa))->next;
	if (pile->size_pa > 2)
		temp->next->previous = temp;
	(*(pile->pa))->next = temp;
	temp->previous = *(pile->pa);
	(*(pile->pa))->previous = NULL;
	write(1, "sa\n", 3);
}

void	swap_b_bis(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pb || !*(pile->pb) || !(*(pile->pb))->next)
		return ;
	temp = *(pile->pb);
	*(pile->pb) = (*(pile->pb))->next;
	temp->next = (*(pile->pb))->next;
	if (pile->size_pb > 2)
		temp->next->previous = temp;
	(*(pile->pb))->next = temp;
	temp->previous = *(pile->pb);
	(*(pile->pb))->previous = NULL;
}

void	swap_a_bis(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pa || !*(pile->pa) || !(*(pile->pa))->next)
		return ;
	temp = *(pile->pa);
	*(pile->pa) = (*(pile->pa))->next;
	temp->next = (*(pile->pa))->next;
	if (pile->size_pa > 2)
		temp->next->previous = temp;
	(*(pile->pa))->next = temp;
	temp->previous = *(pile->pa);
	(*(pile->pa))->previous = NULL;
}

void	swap_ab(t_pile *pile)
{
	swap_a_bis(pile);
	swap_b_bis(pile);
	write(1, "ss\n", 3);
}
