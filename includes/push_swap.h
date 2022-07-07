/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:20:29 by gborne            #+#    #+#             */
/*   Updated: 2022/07/07 14:59:25 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdio.h>

// struct of pile A anb B
typedef struct s_pile
{
	int			*nbr;
	int			size;
	int			temp_size;
}				t_p;

// struct contain data for sort_big.c
typedef struct s_sort_big
{
	int			pivot;
	int			last_pivot;
	int			nb_min;
	int			rest_sort;
	int			box_size;
}				t_s;

int		check(char **list);

// sort stack with size <= 6 (if/else method)
int		sort_small(t_p *a, t_p *b);

// sort stack with size > 6 (range method )
int		sort_big(t_p *a, t_p *b, int box_size);

// return index of the bigger number of pile
int		get_bigger(t_p *p, int start, int end, int value_max);

// return index of the lower number of pile
int		get_miner(t_p *p, int start, int end, int value_min);

/* return pivot of pile, this function shearch in decroissant order, 
margin is the range of shearch */
int		get_pivot(t_p *p, int start, int end, int margin);

// push number by index, a to b
void	push_i_atob(t_p *a, t_p *b, int i_nbr);

// push number by index, b to a
void	push_i_btoa(t_p *a, t_p *b, int i_nbr);

// pile.c
t_p		pile_create(char **list);
t_p		pile_init(int size);
void	pile_print(t_p pile);
void	pile_destroy(t_p *pile);

// command.c
// Shift the 'int tab[]' ... because is not list
void	pile_shift(t_p *pile, int reverse);

// execute command pass in string "ra" - "pb" - "sa" etc..
int		command(t_p *a, t_p *b, char *cmd);

#endif
