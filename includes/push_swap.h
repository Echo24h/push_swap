/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:20:29 by gborne            #+#    #+#             */
/*   Updated: 2022/01/25 03:34:00 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_pile
{
	int			*nbr;
	int			size;
}				t_p;

// check.c
int	find_bigger(t_p pile, int *b);
int	check_max(char **list);
int	check_double(char **list);
int	check_nbr(char **list);
int	check_arg(char **list);

// pile.c
t_p		pile_create(char **list);
t_p		pile_init(int size);
void	pile_fill(t_p *pile, char **list);
void	pile_print(t_p pile);
void	pile_destroy(t_p *pile);


#endif
