/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_rps.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:52:12 by mdiallo           #+#    #+#             */
/*   Updated: 2021/05/31 19:10:14 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	swap_rotate_a(t_pile *pile)
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
	write(1, "ra\n", 3);
}

void	swap_rotate_b(t_pile *pile)
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
	write(1, "rb\n", 3);
}

void	swap_rotate_a_bis(t_pile *pile)
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

void	swap_rotate_b_bis(t_pile *pile)
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

void	swap_rotate_ab(t_pile *pile)
{
	swap_rotate_a_bis(pile);
	swap_rotate_b_bis(pile);
	write(1, "rr\n", 3);
}
