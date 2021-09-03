/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   other.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:53 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 14:44:51 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_bool	check_lst(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
	}
	return (true);
}

t_stack	*last_elm(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

int	last_elm_content(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp->content);
}

char	*ft_strdup(const char *src)
{
	int		size;
	char	*strdp;
	char	*p_strdp;

	size = 0;
	while (src[size])
		size++;
	strdp = (char *) malloc(sizeof(char) * size + 1);
	if (!strdp)
		return (NULL);
	p_strdp = strdp;
	while (*src)
		*p_strdp++ = *src++;
	*p_strdp = '\0';
	return (strdp);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
