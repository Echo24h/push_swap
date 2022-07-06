/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:20:29 by gborne            #+#    #+#             */
/*   Updated: 2022/07/06 19:04:31 by gborne           ###   ########.fr       */
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


int		check(char **list);
int		sort(t_p *a, t_p *b);
int		sort_small(t_p *a, t_p *b);
int		sort_big(t_p *a, t_p *b, int box_size);

// functions.c
int		get_bigger(t_p *p, int start, int end, int value_max);
int		get_miner(t_p *p, int start, int end, int value_min);
int		get_pivot(t_p *p, int start, int end, int margin);
void	push_i_atob(t_p *a, t_p *b, int i_nbr);
void	push_i_btoa(t_p *a, t_p *b, int i_nbr);

// pile.c
t_p		pile_create(char **list);
t_p		pile_init(int size);
void	pile_print(t_p pile);
void	pile_destroy(t_p *pile);

// command.c
void	pile_shift(t_p *pile, int reverse);
int		command(t_p *a, t_p *b, char *cmd);

#endif
