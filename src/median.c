/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   median.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 15:22:18 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/28 15:49:48 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	*_stack(t_pile *pile, int pil)
{
	t_stack	*tmp;

	tmp = NULL;
	if (pil == 1)
		tmp = *(pile->pa);
	else if (pil == 2)
		tmp = *(pile->pb);
	return (tmp);
}

static void	ft_sort_tab(int *tab, int len)
{
	int		i;
	int		tmp;
	int		n;

	n = 0;
	while (n < len - 1)
	{
		i = n + 1;
		while (i < len)
		{
			if (tab[n] > tab[i])
			{
				tmp = tab[n];
				tab[n] = tab[i];
				tab[i] = tmp;
			}
			i++;
		}
		n++;
	}
}

int	ft_median(t_pile *pile, int n, int pil)
{
	t_stack	*tmp;
	int		i;
	int		*tab;
	int		median;

	i = 0;
	tab = (int *)malloc(sizeof(int) * (n + 1));
	if (!tab)
		exit(1);
	tmp = _stack(pile, pil);
	while (i < n && tmp)
	{
		tab[i] = tmp->content;
		i++;
		tmp = tmp->next;
	}
	ft_sort_tab(tab, n);
	if (pil == 2 && n % 2 == 0)
		median = tab[(n / 2) - 1];
	else
		median = tab[(n / 2)];
	free(tab);
	return (median);
}

t_bool	issorted_lst_asc(t_stack **stack, int len)
{
	int		i;
	t_stack	*tmp;

	if (!*stack)
		return (false);
	tmp = *stack;
	i = 0;
	while (tmp->next != NULL && i < len)
	{
		if (tmp->content > tmp->next->content)
			return (false);
		tmp = tmp->next;
		i++;
	}
	return (true);
}

t_bool	issorted_lst_desc(t_stack **stack, int len)
{
	int		i;
	t_stack	*tmp;

	if (!*stack)
		return (false);
	tmp = *stack;
	i = 0;
	while (tmp->next != NULL && i < len)
	{
		if (tmp->content < tmp->next->content)
			return (false);
		tmp = tmp->next;
		i++;
	}
	return (true);
}
