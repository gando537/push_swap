#include "../include/push_swap.h"

static t_bool	check_(t_pile *pile, int len)
{
	if (issorted_lst_desc(pile->pb, len) == true)
	{
		while (len--)
			push_a(pile);
		return (true);
	}
	if (len <= 3)
	{
		sort_2_or_3_b(pile, len);
		return (true);
	}
	return (false);
}

void	_quickSort_b(t_pile *pile, int len)
{
	int		size;
	int		i;
	t_nb_pr	nb_pr;
	int		median;

	size = pile->size_pb;
	if (check_(pile, len) == true)
		return ;
	median = ft_median(pile, len, 2);
	nb_pr = push_or_rotate(pile, median, len, 2);
	i = nb_pr.nb_r;
	if (len != size)
		while (i--)
			swap_rotate_reverse_b(pile);
	_quickSort_a(pile, nb_pr.nb_p);
	_quickSort_b(pile, len - nb_pr.nb_p);
}

void	_quickSort_a(t_pile *pile, int len)
{
	int		size;
	int		i;
	t_nb_pr	nb_pr;
	int		median;

	size = pile->size_pa;
	if (issorted_lst_asc(pile->pa, len) == true)
		return ;
	if (len <= 3)
	{
		sort_2_or_3_a(pile, len);
		return ;
	}
	median = ft_median(pile, len, 1);
	nb_pr = push_or_rotate(pile, median, len, 1);
	i = nb_pr.nb_r;
	if (len != size)
		while (i--)
			swap_rotate_reverse_a(pile);
	_quickSort_a(pile, len - nb_pr.nb_p);
	_quickSort_b(pile, nb_pr.nb_p);
}

void 	algo_sort(t_pile *pile)
{
	if (check_lst(pile->pa) == false)
	{
		if (pile->size_pa == 2)
			swap_a(pile);
		else if (pile->size_pa == 3)
			lst_three_nb(pile);
		else
			_quickSort_a(pile, pile->size_pa);
		return ;
	}
}

int	main(int argc, char **argv)
{
	t_pile	*pile;

	if (argc < 2)
		exit(0);
	pile = NULL;
	pile = ft_init_pile(argc, argv);
	check_arg(pile);
	algo_sort(pile);
	clear_stack(*(pile->pb), &(pile->size_pb));
	clear_stack(*(pile->pa), &(pile->size_pa));
	free(pile);
	return (0);
}
