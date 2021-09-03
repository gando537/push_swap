/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rrps.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:52:15 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/27 01:08:20 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_rotate_reverse_a(t_pile *pile)
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
	write(1, "rra\n", 4);
}

void	swap_rotate_reverse_b(t_pile *pile)
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
	write(1, "rrb\n", 4);
}

void	swap_rotate_reverse_bis_a(t_pile *pile)
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

void	swap_rotate_reverse_bis_b(t_pile *pile)
{
	t_stack	*temp;

	if (!pile->pb || !*(pile->pb) || !(*(pile->pb))->next)
		return ;
	temp = *(pile->pb);
	while (temp->next != NULL)
		temp = temp->next;
	temp->previous->next = NULL;
	temp->previous = NULL;
	temp->next = *(pile->pa);
	(*(pile->pb))->previous = temp;
	*(pile->pb) = temp;
}

void	swap_rotate_reverse_ab(t_pile *pile)
{
	swap_rotate_reverse_bis_a(pile);
	swap_rotate_reverse_bis_b(pile);
	write(1, "rrr\n", 4);
}
