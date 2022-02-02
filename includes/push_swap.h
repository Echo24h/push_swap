/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:20:29 by gborne            #+#    #+#             */
/*   Updated: 2022/02/02 23:05:39 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

typedef struct	s_pile
{
	int			*nbr;
	int			size;
	int			temp_size;
}				t_p;

// main.c
int		main(int argc, char **argv);
void	free_list(char **list);
char	**create_list(int argc, char **argv);

// check.c
int		check_max(char **list);
int		check_min(char **list);
int		check_double(char **list);
int		check_nbr(char **list);
int		check_list(char **list);

// sort.c
int		sort_pile(t_p *a, t_p *b);

// sort_small_stack.c
int		sort_small_stack(t_p *a, t_p *b);
void	sort_small_stack_min(t_p *a, t_p *b, int *count);

// sort_big_stack.c
int		sort_big_stack(t_p *a, t_p *b);
void	sort_b_pile(t_p *a, t_p *b, int *count);

// sort_bigbig_stack.c
int		sort_bigbig_stack(t_p *a, t_p *b, int box_size);

// sort_functions.c
int		find_the_bigger(t_p *p, int start, int end, int value_max);
int		find_the_miner(t_p *p, int start, int end, int value_min);
int		find_the_pivot(t_p *p, int start, int end, int value_max);
void	push_i_nbr_atob(t_p *a, t_p *b, int *count, int i_nbr);
void	push_i_nbr_btoa(t_p *a, t_p *b, int *count, int i_nbr);

// pile.c
t_p		pile_create(char **list);
t_p		pile_init(int size);
void	pile_fill(t_p *pile, char **list);
void	pile_print(t_p pile);
void	pile_destroy(t_p *pile);

// command.c
void	swap(t_p *p);
void	push(t_p *src, t_p *dst);
void	rotate(t_p *p);
void	reverse_rotate(t_p *p);

// command_main.c
int		command(t_p *a, t_p *b, char *cmd);
void	command_p_s_r(t_p *a, t_p *b, char *cmd);
void	command_rr(t_p *a, t_p *b, char *cmd);

#endif
