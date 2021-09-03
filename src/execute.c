/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   execute.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:21 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 14:20:40 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	_execut_0_(t_cmd *tmp, t_pile *pile)
{
	if (ft_strcmp(tmp->content, "pa") == 0)
	{
		push_ach(pile);
		return (true);
	}
	if (ft_strcmp(tmp->content, "pb") == 0)
	{
		push_bch(pile);
		return (true);
	}
	return (false);
}

t_bool	_execut_1_(t_cmd *tmp, t_pile *pile)
{
	if (ft_strcmp(tmp->content, "sa") == 0)
	{
		swap_ach(pile);
		return (true);
	}
	if (ft_strcmp(tmp->content, "sb") == 0)
	{
		swap_bch(pile);
		return (true);
	}
	if (ft_strcmp(tmp->content, "ss") == 0)
	{
		swap_abch(pile);
		return (true);
	}
	return (false);
}

t_bool	_execut_2_(t_cmd *tmp, t_pile *pile)
{
	if (_execut_0_(tmp, pile) == true || _execut_1_(tmp, pile) == true)
		return (true);
	return (false);
}

void	_execut_3_(t_cmd *tmp, t_pile *pile)
{
	if (ft_strcmp(tmp->content, "ra") == 0)
		swap_rotate_ach(pile);
	else if (ft_strcmp(tmp->content, "rb") == 0)
		swap_rotate_bch(pile);
	else if (ft_strcmp(tmp->content, "rr") == 0)
		swap_rotate_abch(pile);
	else if (ft_strcmp(tmp->content, "rra") == 0)
		swap_rotate_reverse_ach(pile);
	else if (ft_strcmp(tmp->content, "rrb") == 0)
		swap_rotate_reverse_bch(pile);
	else if (ft_strcmp(tmp->content, "rrr") == 0)
		swap_rotate_reverse_abch(pile);
}

void	ft_execute(t_pile *pile, t_cmd **cmd)
{
	t_cmd	*tmp;

	tmp = *cmd;
	while (tmp)
	{
		if (_execut_2_(tmp, pile) == false)
			_execut_3_(tmp, pile);
		tmp = tmp->next;
	}
}
