/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rrch.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:33:24 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 14:13:47 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_rotate_reverse_ach(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pa || !*(pile->pa) || !(*(pile->pa))->next)
		return ;
	temp = *(pile->pa);
	while (temp->next != NULL)
		temp = temp->next;
	temp->previous->next = NULL;
	temp->previous = NULL;
	temp->next = *(pile->pa);
	(*(pile->pa))->previous = temp;
	*(pile->pa) = temp;
}

void	swap_rotate_reverse_bch(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pb || !*(pile->pb) || !(*(pile->pb))->next)
		return ;
	temp = *(pile->pb);
	while (temp->next != NULL)
		temp = temp->next;
	temp->previous->next = NULL;
	temp->previous = NULL;
	temp->next = *(pile->pb);
	(*(pile->pb))->previous = temp;
	*(pile->pb) = temp;
}

void	swap_rotate_reverse_abch(t_pile *pile)
{
	swap_rotate_reverse_ach(pile);
	swap_rotate_reverse_bch(pile);
}
