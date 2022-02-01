/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gborne <gborne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/25 02:20:29 by gborne            #+#    #+#             */
/*   Updated: 2022/02/01 05:47:26 by gborne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

typedef struct	s_pile
{
	int			*nbr;
	int			size;
	int			temp_size;
}				t_p;

// check.c
int		check_max(char **list);
int		check_min(char **list);
int		check_double(char **list);
int		check_nbr(char **list);
char	**check_list(char **list);

// sort.c
int		sort_pile(t_p *a, t_p *b);
int		sort_big_stack(t_p *a, t_p *b);
int		find_the_bigger(t_p *p);
void	push_the_bigger(t_p *a, t_p *b, int *count);

// sort_small_stack.c
int		sort_small_stack(t_p *a, t_p *b);
void	sort_small_stack_min(t_p *a, t_p *b, int *count);

// box.c
int		**box_init(int nb, int size);
void	box_free(int **box);

// pile.c
t_p		pile_create(char **list);
t_p		pile_init(int size);
void	pile_fill(t_p *pile, char **list);
void	pile_print(t_p pile);
void	pile_destroy(t_p *pile);

// functions.c
void	swap(t_p *p);
void	push(t_p *src, t_p *dst);
void	rotate(t_p *p);
void	reverse_rotate(t_p *p);

// functions_commands.c
int		command(t_p *a, t_p *b, char *cmd);
void	command_p_s_r(t_p *a, t_p *b, char *cmd);
void	command_rr(t_p *a, t_p *b, char *cmd);

#endif
