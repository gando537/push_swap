/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:43 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 14:44:22 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_pile	*ft_init_pile(int argc, char **argv)
{
	t_pile	*pile;

	pile = malloc(sizeof(t_pile));
	if (!pile)
		return (0);
	pile->pb = create_stack();
	pile->pa = ft_init_pa(argc, argv, pile);
	pile->size_pa = size_stack(pile->pa);
	pile->size_pb = 0;
	return (pile);
}
