/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lst_three.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:50 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/22 21:50:04 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	lst_three_nb(t_pile *pile)
{
	int	top;
	int	middle;
	int	bottom;

	top = (*(pile->pa))->content;
	middle = (*(pile->pa))->next->content;
	bottom = last_elm_content(pile->pa);
	if (top > middle && middle < bottom && bottom > top)
		swap_a(pile);
	else if (top > middle && middle < bottom && bottom < top)
		swap_rotate_a(pile);
	else if (top < middle && middle > bottom && bottom < top)
		swap_rotate_reverse_a(pile);
	else if (top > middle && middle > bottom && bottom < top)
	{
		swap_a(pile);
		swap_rotate_reverse_a(pile);
	}
	else if (top < middle && middle > bottom && bottom > top)
	{
		swap_a(pile);
		swap_rotate_a(pile);
	}
}
