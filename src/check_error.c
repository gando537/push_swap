/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:02 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 15:09:43 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	check_doublon(t_pile *pile)
{
	t_stack	*tmp;
	t_stack	*temp;

	temp = (*(pile->pa))->next;
	while (temp)
	{
		tmp = *(pile->pa);
		while (tmp != temp)
		{
			if (tmp->content == temp->content)
				return (true);
			tmp = tmp->next;
		}
		temp = temp->next;
	}
	return (false);
}

void	check_arg(t_pile *pile)
{
	if (*(pile->pa))
	{
		if (check_doublon(pile) == true)
		{
			clear_stack(*(pile->pa), &(pile->size_pa));
			free(pile);
			write(2, "Error\n", 6);
			exit (0);
		}
	}
}

char	*ft_checkcom(char *str, t_pile *pile, t_stack **stack, t_cmd **cmd)
{
	if (ft_strcmp("sa", str) != 0 && \
	ft_strcmp("sb", str) != 0 && \
	ft_strcmp("ss", str) != 0 && \
	ft_strcmp("ra", str) != 0 && \
	ft_strcmp("rb", str) != 0 && \
	ft_strcmp("rr", str) != 0 && \
	ft_strcmp("rrr", str) != 0 && \
	ft_strcmp("rra", str) != 0 && \
	ft_strcmp("rrb", str) != 0 && \
	ft_strcmp("pb", str) != 0 && \
	ft_strcmp("pa", str) != 0)
	{
		free_cmd(cmd);
		all_free(pile, stack, str);
	}
	return (str);
}
