/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rch.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 15:23:00 by mdiallo           #+#    #+#             */
/*   Updated: 2021/05/31 19:00:35 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_rotate_ach(t_pile *pile)
{
	t_stack	*tmp;

	if (!pile->pa || !*(pile->pa) || !(*(pile->pa))->next)
		return ;
	tmp = *(pile->pa);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *(pile->pa);
	(*(pile->pa))->previous = tmp;
	tmp = *(pile->pa);
	*(pile->pa) = (*(pile->pa))->next;
	(*(pile->pa))->previous = NULL;
	tmp->next = NULL;
}

void	swap_rotate_bch(t_pile *pile)
{
	t_stack	*tmp;

	if (!pile->pb || !*(pile->pb) || !(*(pile->pb))->next)
		return ;
	tmp = *(pile->pb);
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *(pile->pb);
	(*(pile->pb))->previous = tmp;
	tmp = *(pile->pb);
	*(pile->pb) = (*(pile->pb))->next;
	(*(pile->pb))->previous = NULL;
	tmp->next = NULL;
}

void	swap_rotate_abch(t_pile *pile)
{
	swap_rotate_ach(pile);
	swap_rotate_bch(pile);
}
