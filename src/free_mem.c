/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:29 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 14:51:48 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	all_free(t_pile *pile, t_stack **stack, char *str)
{
	clear_stack(*stack, &(pile->size_pa));
	free(stack);
	free(pile->pb);
	free(pile);
	if (ft_strcmp("Error", str) != 0)
		write(2, "Error\n", 6);
	exit (0);
}

t_stack	*free_elm(t_stack **stack, int *size)
{
	t_stack	*tmp;

	if (!*stack)
		return (*stack);
	tmp = (*stack)->next;
	if (!tmp)
	{
		free(*stack);
		*stack = NULL;
		*size -= 1;
		return (NULL);
	}
	*size -= 1;
	free(*stack);
	tmp->previous = NULL;
	return (tmp);
}

void	clear_stack(t_stack *stack, int *size)
{
	t_stack	*elm;

	if (!stack)
		return ;
	elm = stack;
	while (elm != NULL)
		elm = free_elm(&elm, size);
}

void	free_cmd(t_cmd **cmd)
{
	t_cmd	*tmp;

	if (!cmd || !*cmd)
		return ;
	if (!(*cmd)->next)
	{
		free(*cmd);
		free(cmd);
		return ;
	}
	tmp = *cmd;
	while (tmp)
	{
		tmp = tmp->next;
		free(*cmd);
		*cmd = tmp;
	}
	free(cmd);
}

void	ft_strdel(char **as)
{
	if (as != NULL)
	{
		free(*as);
		*as = NULL;
	}
}
