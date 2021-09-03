/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:33 by mdiallo           #+#    #+#             */
/*   Updated: 2021/05/31 19:06:18 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	get_next_line_bis(char **line, char *tmp, int l, char c)
{
	int		i;

	i = -1;
	while (++i < l - 2)
		tmp[i] = (*line)[i];
	tmp[i] = c;
	tmp[i + 1] = 0;
	free(*line);
	*line = tmp;
}

int	get_next_line(char **line)
{
	int		l;
	int		r;
	char	c;
	char	*tmp;

	r = 0;
	l = 1;
	*line = malloc(l);
	if (!*line)
		return (-1);
	(*line)[0] = 0;
	r = read(0, &c, 1);
	while (r && l++ && c != '\n')
	{
		tmp = malloc(l);
		if (!tmp)
		{
			free(*line);
			return (-1);
		}
		get_next_line_bis(line, tmp, l, c);
		r = read(0, &c, 1);
	}
	return (r);
}
