/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_ch.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:18:38 by mdiallo           #+#    #+#             */
/*   Updated: 2021/05/31 19:16:27 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_bch(t_pile *pile)
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

void	swap_ach(t_pile *pile)
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

void	swap_b_bisch(t_pile *pile)
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

void	swap_a_bisch(t_pile *pile)
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

void	swap_abch(t_pile *pile)
{
	swap_a_bisch(pile);
	swap_b_bisch(pile);
}
