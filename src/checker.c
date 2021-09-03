/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:51:06 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 14:37:22 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

t_cmd	**ft_getcom(t_pile *pile, t_stack **stack)
{
	t_cmd	**com;
	char	*str;

	com = stack_cmd();
	str = NULL;
	while (get_next_line(&str) == 1)
	{
		ft_newcom(ft_checkcom(ft_strdup(str), pile, stack, com), com);
		ft_strdel(&str);
	}
	return (com);
}

int	main(int argc, char **argv)
{
	t_pile	*pile;
	t_cmd	**com;

	if (argc < 2)
		exit(0);
	com = NULL;
	pile = NULL;
	pile = ft_init_pile(argc, argv);
	check_arg(pile);
	com = ft_getcom(pile, pile->pa);
	ft_execute(pile, com);
	if (check_lst(pile->pa) == true && pile->size_pb == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	clear_stack(*(pile->pb), &(pile->size_pb));
	clear_stack(*(pile->pa), &(pile->size_pa));
	free_cmd(com);
	free(pile);
	return (0);
}
