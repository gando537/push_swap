/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_pa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:39 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 15:12:39 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_stack	**ft_init(int argc, char **argv, t_pile *pile)
{
	int		i;
	long	nbr;
	t_stack	*new;
	t_stack	**stack;
	char	*s;

	stack = create_stack();
	i = 0;
	while (++i < argc)
	{
		nbr = 0;
		s = argv[i];
		mini_atoi(s, &nbr, stack, pile);
		new = ft_new_elm((int)nbr);
		push_back_stack(stack, new);
	}
	return (stack);
}

t_stack	**ft_init_bis(char *arg, t_pile *pile)
{
	long	nbr;
	t_stack	*new;
	t_stack	**stack;
	char	*s;
	int		ret;

	stack = create_stack();
	s = arg;
	if (!*s)
		exit(0);
	while (*s)
	{
		nbr = 0;
		ret = mini_atoi_bis(s, &nbr, stack, pile);
		new = ft_new_elm((int)nbr);
		push_back_stack(stack, new);
		s = s + ret;
		if (*s)
			s++;
	}
	return (stack);
}

t_stack	**ft_init_pa(int argc, char **argv, t_pile *pile)
{
	t_stack	**stackA;

	if (argc != 2)
		stackA = ft_init(argc, argv, pile);
	else
		stackA = ft_init_bis(argv[1], pile);
	if (size_stack(stackA) <= 1)
		exit (0);
	return (stackA);
}
