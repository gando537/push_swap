/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   correct_spot.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:14 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/28 15:47:44 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

static t_bool	vreif(t_pile *pile, int len)
{
	if (len == 1)
		return (true);
	if (len >= 2 && (*(pile->pb))->content > \
			(*(pile->pb))->next->content)
		return (true);
	if (len == 3)
	{
		if ((*(pile->pb))->content > \
				(*(pile->pb))->next->next->content)
			return (true);
	}
	return (false);
}

static void	check_lst3_b(t_pile *pile, int len)
{
	while (len || !((*(pile->pa))->content < \
		(*(pile->pa))->next->content \
		&& (*(pile->pa))->next->content < \
		(*(pile->pa))->next->next->content))
	{
		if (len == 1 && (*(pile->pa))->content > \
				(*(pile->pa))->next->content)
			swap_a(pile);
		else if (vreif(pile, len) == true)
		{
			push_a(pile);
			len--;
		}
		else
			swap_b(pile);
	}
}

void	sort_2_or_3_b(t_pile *pile, int len)
{
	if (len == 1)
		push_a(pile);
	else if (len == 2)
	{
		if ((*(pile->pb))->content < (*(pile->pb))->next->content)
			swap_b(pile);
		push_a(pile);
		push_a(pile);
	}
	else if (len == 3)
		check_lst3_b(pile, len);
}

static void	check_lst3_a(t_pile *pile, int len)
{
	while (len != 3 || !((*(pile->pa))->content < (*(pile->pa))->next->content
			&& (*(pile->pa))->next->content < \
			(*(pile->pa))->next->next->content))
	{
		if (len == 3 && (*(pile->pa))->content > (*(pile->pa))->next->content
			&& (*(pile->pa))->next->next->content)
			swap_a(pile);
		else if (len == 3 || !((*(pile->pa))->next->next->content > \
			(*(pile->pa))->content && (*(pile->pa))->next->next->content > \
			(*(pile->pa))->next->content))
		{
			push_b(pile);
			len--;
		}
		else if ((*(pile->pa))->content > (*(pile->pa))->next->content)
			swap_a(pile);
		else if (len++)
			push_a(pile);
	}
}

void	sort_2_or_3_a(t_pile *pile, int len)
{
	if (pile->size_pa == 3 && len == 3)
		lst_three_nb(pile);
	else if (len == 2)
	{
		if ((*(pile->pa))->content > (*(pile->pa))->next->content)
			swap_a(pile);
	}
	else if (len == 3)
		check_lst3_a(pile, len);
}
