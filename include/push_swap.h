/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mdiallo <mdiallo@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/05/31 14:23:27 by mdiallo           #+#    #+#             */
/*   Updated: 2021/06/29 20:58:35 by mdiallo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef enum e_bool
{
	false,
	true
}t_bool;

typedef struct s_stack
{
	int				content;
	struct s_stack	*next;
	struct s_stack	*previous;
}				t_stack;

typedef struct s_cmd
{
	char			*content;
	struct s_cmd	*next;
}				t_cmd;

typedef struct s_nb_pr
{
	int				nb_p;
	int				nb_r;
}				t_nb_pr;

typedef struct s_mp
{
	int				m;
	int				p;
	int				l;
	t_stack			*stack;
}				t_mp;

typedef struct s_pile
{
	t_stack		**pa;
	t_stack		**pb;
	t_stack		*pivot;
	t_stack		*max;
	t_stack		*max_n;
	int			first;
	int			last;
	int			size_pa;
	int			size_pb;
}				t_pile;

t_stack			*ft_new_elm(int content);
t_stack			*create_elem(void);
t_stack			**create_stack(void);
t_bool			check_doublon(t_pile *pile);
void			check_arg(t_pile *pile);
void			all_free(t_pile *pile, t_stack **stack, char *str);
void			mini_atoi(char *s, long *n, t_stack **stack, t_pile *pile);
int				mini_atoi_bis(char *s, long *n, t_stack **stack, t_pile *pile);
t_stack			**ft_init(int argc, char **argv, t_pile *pile);
t_stack			**ft_init_bis(char *arg, t_pile *pile);
t_stack			**ft_init_pa(int argc, char **argv, t_pile *pile);
t_pile			*ft_init_pile(int argc, char **argv);
void			push_back_stack(t_stack **stack, t_stack *new);
t_stack			*push_front_stack(t_stack **stack, int val);
t_stack			*find_min(t_stack **stack);
t_stack			*find_max(t_stack **stack);
void			push_a_bis(t_pile *pile, t_stack *stackB);
void			push_b_bis(t_pile *pile, t_stack *stackA);
void			push_a(t_pile *pile);
void			push_b(t_pile *pile);
void			push_ach(t_pile *pile);
void			push_bch(t_pile *pile);
int				size_stack(t_stack **stack);
void			swap_b(t_pile *pile);
void			swap_a(t_pile *pile);
void			swap_rotate_a(t_pile *pile);
void			swap_rotate_b(t_pile *pile);
void			swap_rotate_reverse_a(t_pile *pile);
void			swap_rotate_reverse_b(t_pile *pile);
void			swap_bch(t_pile *pile);
void			swap_ach(t_pile *pile);
void			swap_abch(t_pile *pile);
void			swap_rotate_ach(t_pile *pile);
void			swap_rotate_bch(t_pile *pile);
void			swap_rotate_abch(t_pile *pile);
void			swap_rotate_reverse_ach(t_pile *pile);
void			swap_rotate_reverse_bch(t_pile *pile);
void			swap_rotate_reverse_abch(t_pile *pile);
t_bool			check_lst(t_stack **stack);
t_stack			*last_elm(t_stack **stack);
t_stack			*free_elm(t_stack **stack, int *size);
void			clear_stack(t_stack *stack, int *size);
int				last_elm_content(t_stack **stack);
void			lst_three_nb(t_pile *pile);
void			lst_15(t_pile *pile, int size, int pil);
t_stack			*_stack(t_pile *pile, int pil);
t_nb_pr			push_or_rotate(t_pile *pile, int median, int len, int pil);
void			sort_2_or_3_b(t_pile *pile, int len);
void			sort_2_or_3_a(t_pile *pile, int len);
t_bool			issorted_lst_asc(t_stack **stack, int len);
t_bool			issorted_lst_desc(t_stack **stack, int len);
int				ft_median(t_pile *pile, int n, int pil);
void			_quickSort_a(t_pile *pile, int len);
void			algo_sort(t_pile *pile);

void			get_next_line_bis(char **line, char *tmp, int l, char c);
int				get_next_line(char **line);
char			*ft_strdup(const char *src);
int				ft_strcmp(char *s1, char *s2);
void			free_cmd(t_cmd **cmd);
char			*ft_checkcom(char *str, t_pile *pile,
					t_stack **stack, t_cmd **cmd);
void			ft_strdel(char **as);
t_cmd			*new_cmd(char *str);
t_cmd			**stack_cmd(void);
void			ft_newcom(char *str, t_cmd **com);
t_cmd			**ft_getcom(t_pile *pile, t_stack **stack);
t_bool			_execut_0_(t_cmd *tmp, t_pile *pile);
t_bool			_execut_1_(t_cmd *tmp, t_pile *pile);
t_bool			_execut_2_(t_cmd *tmp, t_pile *pile);
void			_execut_3_(t_cmd *tmp, t_pile *pile);
void			ft_execute(t_pile *pile, t_cmd **cmd);

#endif
