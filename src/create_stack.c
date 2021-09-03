/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_stack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:18 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 12:37:58 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*ft_new_elm(int content)
{
	t_stack	*new_maillon;

	new_maillon = malloc(sizeof(t_stack));
	if (!new_maillon)
		return (NULL);
	new_maillon->content = content;
	new_maillon->next = NULL;
	new_maillon->previous = NULL;
	return (new_maillon);
}

t_stack	*create_elem(void)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	return (new);
}

t_stack	**create_stack(void)
{
	t_stack	**new;

	new = malloc(sizeof(t_stack *));
	if (!new)
		return (NULL);
	*new = NULL;
	return (new);
}
