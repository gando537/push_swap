/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cmd.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:36 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 12:30:08 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cmd	*new_cmd(char *str)
{
	t_cmd	*new;

	new = malloc(sizeof(t_cmd));
	if (!new)
		return (NULL);
	new->content = str;
	new->next = NULL;
	return (new);
}

t_cmd	**stack_cmd(void)
{
	t_cmd	**com;

	com = malloc(sizeof(t_cmd *));
	if (!com)
		return (NULL);
	*com = NULL;
	return (com);
}

void	ft_newcom(char *str, t_cmd **com)
{
	t_cmd	*new_com;
	t_cmd	*p_cmd;

	if (!com)
		return ;
	new_com = new_cmd(str);
	if (!*com)
	{
		*com = new_com;
		return ;
	}
	p_cmd = *com;
	while (p_cmd->next != NULL)
		p_cmd = p_cmd->next;
	p_cmd->next = new_com;
}
